const express = require('express'); // express
const sqlite3 = require('sqlite3').verbose(); // ajout pour SQLite3
const bcrypt = require('bcrypt'); // ajout pour le hashage des mots de passe
const path = require('path'); // fichier 
const { permission } = require('process');

//const db = new sqlite3.Database('./');

class RoxExpress{

    constructor(app, ip, port){
        this.app = app; 
        this.port = port;
        this.ip = ip;
        //this.middlewares();
        //this.routes();
    };

    
    middlewares(){
        this.app.use(express.json());
    };


    Route401(url){
        this.app.get(url, (req, res)=>{
            res.status(401).send("Acces Interdit ");
            
        });
    }

    // prend l'url example :  '/Alex', 'index.html' et indique le nom du fichier
    RouteGet(url, FileInPublic){
        this.app.get(url, (req, res) => {
            res.redirect(FileInPublic); 
        });
    };

    // ou tu envoi des donné json 
    RouteSendJson(url, data){
        this.app.get(url, (req, res) =>{
            res.send(data);
        });
    };

    routesLogin(url, table, colomn, methode){
        if(methode === "post"){
            this.app.post(url, (req, res) => {
                const {username, password} = req.body;
                const sql = `SELECT * FROM ${table} WHERE ${colomn} = ?`;
                
            });
        }else if(methode === "get"){
            this.app.get(url, (req, res) => {
                const {username, password} = req.body;
                const sql = `SELECT * FROM ${table} WHERE ${colomn} = ?`;
                
            });
        }else{
            res.status(405).send("Method not allowed");
        }
    };


    StaticFilePUBLIC(){
        this.app.use(express.static(path.join(__dirname, 'public')));
    };

    
    IsUrlIfRedirect(url, url_redirect){
        this.app.get(url, (req, res) =>{
            res.redirect(301, url_redirect);
        });
    }




    listen(){
        this.app.listen(this.port, this.ip, () =>  {
            console.log(`Server is running http://${this.ip}:${this.port}`);
        });
    };

};

module.exports = RoxExpress;



const app = express();
const apli = new RoxExpress(app, "127.0.0.1", 8000);


// Appeler le middleware 
apli.middlewares();
apli.StaticFilePUBLIC();
apli.Route401('/'); 
apli.RouteGet('/Alex', './Alex.html'); // page 

apli.RouteSendJson('/api', {"name": "Tina", "name": "Theo"});



apli.listen();


/*
documentation express :
https://expressjs.com/en/api.html

documentation bcrypt :
https://github.com/kelektiv/node.bcrypt.js#usage

documentation sqlite3 : 
https://github.com/TryGhost/node-sqlite3/wiki#documentation

node RoxExpress.js
*/
