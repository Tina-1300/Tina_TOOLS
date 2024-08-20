<?php
/**
 * Tina_Binary_Read_File
 * 
 * cette class permet de lire le contenu d'un fichier en binaire 
 */
class Tina_Binary_Read_File{

    /**
     * Read_File_Result_To_Binary
     * @param [string $NameFile] attend en paramètre le nom du fichier a lire en binaire
     * 
     * Cette fonction permet de lire le contenu d'un fichier en binaire
     */
    public static function Read_File_Result_To_Binary(string $NameFile){
        $contents = file_get_contents($NameFile);
        $binaryString = '';
        for($i = 0; $i < strlen($contents); $i++){
            $asciiValue = ord($contents[$i]);
            $binaryString .= str_pad(decbin($asciiValue), 8, '0', STR_PAD_LEFT);
        }
        return $binaryString;
    }

    public static function Read_File_Result_To_Hexa(string $NameFile){
        $content = file_get_contents($NameFile);
        $HexaString =  '';
        for($i = 0; $i < strlen($content); $i++){
            $asciiValue = ord($content[$i]);
            $HexaString .= str_pad(dechex($asciiValue), 2, '0', STR_PAD_LEFT);
        }
        return $HexaString;
    }

    public static function Read_File_Result_To_Oct(string $NameFile){
        $content = file_get_contents($NameFile);
        $OctString =  '';
        for($i = 0; $i < strlen($content); $i++){
            $asciiValue = ord($content[$i]);
            $OctString .= str_pad(decoct($asciiValue), 2, '0', STR_PAD_LEFT);
        }
        return $OctString;
    }

}



/*
bindec() - Convertit de binaire en décimal
decoct() - Convertit de décimal en octal
dechex() - Convertit de décimal en hexadécimal
decbin() - Convertit de décimal en binaire
*/


?>