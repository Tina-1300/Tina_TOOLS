const regedit = require('regedit'); // https://www.npmjs.com/package/regedit
const { exec } = require('child_process');
//const ffi = require('ffi-napi');


class Lana_REG{

    Lana_READ_A_KEY(key){
        regedit.list(key, (err, result) => {
            if (err){
                console.error('Erreur lors de la lecture de la clé : ', err);
            }else{
                console.log('Résultat de la lecture : ', result);
            }
        });
    }


    Lana_CREATE_KEY_AND_ADD_VALUE(parentKey, valuee, namekey){
        let commande = 'reg add "'+parentKey+'" /v '+namekey+' /d "'+valuee+'" /f';
        exec(commande, (error, stdout, stderr) => {
            if (error){
                console.error(`Erreur : ${error}`);
                return;
            }
            if (stderr){
                console.error(`Stderr : ${stderr}`);
                return;
            }
            console.log(`Stdout : ${stdout}`);
        });
    }



    Lana_DELET_KEY_REGISTER(parentKey, namekey){
        let commande = 'reg delete "'+parentKey+'" /v '+namekey+' /f';
        exec(commande, (error, stdout, stderr) => {
            if (error){
                console.error(`Erreur : ${error}`);
                return;
            }
            if (stderr){
                console.error(`Stderr : ${stderr}`);
                return;
            }
            console.log(`Stdout : ${stdout}`);
        });
    }


    
}

module.exports =  Lana_REG;