<?php
declare (strict_types=1);


class Tina_Operation_Binaire{


    public static function Tina_Operation_Bits(string $nb1, string $nb2,string $type_operation_enter) : string{
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

/*
$Tina_opp = new Tina_Operation_Binaire();
echo $Tina_opp->Tina_Operation_Bits("00101", "10110", "xor");
*/
?>