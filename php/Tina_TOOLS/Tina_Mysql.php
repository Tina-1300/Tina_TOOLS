<?php

define("TCF_R_ERROR", "211"); // Tous les champs du formulaire doivent être remplis

class Tina_Mysql{


    /**
     * La méthode tin_requestSQL doit permettre d'envoyer des données à la BDD sans injection SQL possible.
     * 
     * example d'utilisation :
     * 
     * $servername_TINA = "localhost"; // Adresse du serveur MySQL
     * $username_TINA = "root"; // Nom d'utilisateur MySQL
     * $password_TINA = ""; // Mot de passe MySQL
     * $database_TINA = "github"; // Nom de la bdd
     *
     *  if (isset($_POST['login'], $_POST['password'])){
     *     $login = $_POST['login'];
     *     $password = $_POST['password'];
     *
     *     Tina_Mysql::tin_requestSQL(
     *         $servername_TINA, // Adresse du serveur MySQL
     *         $username_TINA, // Nom d'utilisateur MySQL
     *         $password_TINA, // Mot de passe MySQL
     *         $database_TINA, // Nom de la bdd
     *          'user', // Table de la bdd spécifier
     *          'login, password', // colone spécifier 
     *          '?, ?', // nombre de paramètre spécifier pour la requête a preparer 
     *          "$login, $password", // paramètre a envoyer
     *          "https://github.com/login" // url sur la quelle rediriger 
     *      );
     *  }else{
     *      echo TCF_R_ERROR; // return 211 qui veut dire (Tous les champs du formulaire doivent être remplis)
     *  }
     * 
     */
    public static function tin_requestSQL($servername_TINA, $username_TINA, $password_TINA, $database_TINA, $table_sql, $columns, $interrogation, $param_send, $url_red){

        $conn = new mysqli($servername_TINA, $username_TINA, $password_TINA, $database_TINA);

        if ($conn->connect_error){
            die("error de connexion a la bdd : " . $conn->connect_error);
        }

        $sql = "INSERT INTO $table_sql ($columns) VALUES ($interrogation)";
        $stmt = $conn->prepare($sql);

        if ($stmt === false){
            die("error requête preparer : " . $conn->error);
        }
        $params = explode(", ", $param_send);
        $types = str_repeat("s", count($params));

        $stmt->bind_param($types, ...$params);

        if ($stmt->execute()){
            header("Location: $url_red");
        }else{
            echo "error lors de l'ajout des donner : " . $stmt->error;
        }

        $stmt->close();
        $conn->close();
    }


}
