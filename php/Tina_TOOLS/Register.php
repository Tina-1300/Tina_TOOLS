<?php
//Cette class permet de sois ajouter ou sois suprimmer des cle de registre sous windows 

class Register{
    public $parentKey;
    public $namekey;
    public $valuee;

    public function __construct($parentKey, $namekey, $valuee){
        $this->parentKey = $parentKey;
        $this->namekey = $namekey;
        $this->valuee = $valuee;
    }

    public function AddKeyRegister(){
        system("reg add ".$this->parentKey." /v ".$this->namekey." /d ".$this->valuee." /f");     
    }

    public function DeletKeyRegister(){
        system("reg delete ".$this->parentKey." /v ".$this->namekey." /f");
    }

};