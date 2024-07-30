<?php
/**
 * Tina_Operation_Binaire
 * et une class qui permet de faire des opération binaire
 */


class Tina_Operation_Binaire{
    /**
     * Tina_Operation_Bits()
     * @param [string $nb1] attend un paramètre de type string 
     * @param [string $nb2] attend un paramètre de type string
     * @param [string $type_operation_enter] attend un paramètre de type string 
     * 
     * Cette function permet de faire des oppération binnaire en choisisant le type d'opération binaire a faire
     * et on peut l'utiliser comme ça la function il y a 2 méthode différente a passer dans le paramètre 
     * string $type_operation_enter ces méthode sont stoquer dans un tableau
     * "xor"
     * "and"
     * "or" 
     * test
     * $Tina_opp->Tina_Operation_Bits("00101", "10110", "xor");
     * $Tina_opp->Tina_Operation_Bits("00101", "10110", "and");
     * $Tina_opp->Tina_Operation_Bits("00101", "10110", "or");
     */
    public static function Tina_Operation_Bits(string $nb1, string $nb2,string $type_operation_enter){
        $x = bindec($nb1);$y= bindec($nb2);
        $type_operation = ["xor", "and", "or"];
        if($type_operation[0] === $type_operation_enter){
            $result = $x ^ $y;return decbin($result);
        }if($type_operation[1] === $type_operation_enter){
            $result = $x & $y;return decbin($result);
        }if($type_operation[2] === $type_operation_enter){
            $result = $x | $y;return decbin($result);
        }else{
            return 404; // GOOD WORK [-_-] MDR
        }
        return 0;
    }

}

/*$Tina_opp = new Tina_Operation_Binaire();
echo $Tina_opp->Tina_Operation_Bits("00101", "10110", "xor");*/




?>