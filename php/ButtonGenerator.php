<?php

class ButtonGenerator{
    private $buttons;
    private $css;
    private $css_1;
    private $css_2;
    private $css_3;
    private $css_4;
    private $css_5;
    private $css_6;
    private $css_7;
    private $css_8;



    public function __construct(){
        $this->buttons = "";
        $this->css = "<style>
            .orange-button {
                background-color: darkorange;
                color: black;
                border: none;
                border-radius: 5px;
                padding: 5px 10px;
                font-size: 16px;
                cursor: pointer;
            }
        </style>";

        $this->css_1 = "<style>
        .button-63 {
          align-items: center;
          background-image: linear-gradient(144deg,#AF40FF, #5B42F3 50%,#00DDEB);
          border: 0;
          border-radius: 8px;
          box-shadow: rgba(151, 65, 252, 0.2) 0 15px 30px -5px;
          box-sizing: border-box;
          color: #FFFFFF;
          display: flex;
          font-family: Phantomsans, sans-serif;
          font-size: 20px;
          justify-content: center;
          line-height: 1em;
          max-width: 100%;
          min-width: 140px;
          padding: 19px 24px;
          text-decoration: none;
          user-select: none;
          -webkit-user-select: none;
          touch-action: manipulation;
          white-space: nowrap;
          cursor: pointer;
        }
        
        .button-63:active,
        .button-63:hover {
          outline: 0;
        }
        
        @media (min-width: 768px) {
          .button-63 {
            font-size: 24px;
            min-width: 196px;
          }
        }</style>";


        $this->css_2 = "<style>.button-78 {
            align-items: center;
            appearance: none;
            background-clip: padding-box;
            background-color: initial;
            background-image: none;
            border-style: none;
            box-sizing: border-box;
            color: #fff;
            cursor: pointer;
            display: inline-block;
            flex-direction: row;
            flex-shrink: 0;
            font-family: Eina01,sans-serif;
            font-size: 16px;
            font-weight: 800;
            justify-content: center;
            line-height: 24px;
            margin: 0;
            min-height: 64px;
            outline: none;
            overflow: visible;
            padding: 19px 26px;
            pointer-events: auto;
            position: relative;
            text-align: center;
            text-decoration: none;
            text-transform: none;
            user-select: none;
            -webkit-user-select: none;
            touch-action: manipulation;
            vertical-align: middle;
            width: auto;
            word-break: keep-all;
            z-index: 0;
          }
          
          @media (min-width: 768px) {
            .button-78 {
              padding: 19px 32px;
            }
          }
          
          .button-78:before,
          .button-78:after {
            border-radius: 80px;
          }
          
          .button-78:before {
            background-image: linear-gradient(92.83deg, #ff7426 0, #f93a13 100%);
            content: '';
            display: block;
            height: 100%;
            left: 0;
            overflow: hidden;
            position: absolute;
            top: 0;
            width: 100%;
            z-index: -2;
          }
          
          .button-78:after {
            background-color: initial;
            background-image: linear-gradient(#541a0f 0, #0c0d0d 100%);
            bottom: 4px;
            content: '';
            display: block;
            left: 4px;
            overflow: hidden;
            position: absolute;
            right: 4px;
            top: 4px;
            transition: all 100ms ease-out;
            z-index: -1;
          }
          
          .button-78:hover:not(:disabled):before {
            background: linear-gradient(92.83deg, rgb(255, 116, 38) 0%, rgb(249, 58, 19) 100%);
          }
          
          .button-78:hover:not(:disabled):after {
            bottom: 0;
            left: 0;
            right: 0;
            top: 0;
            transition-timing-function: ease-in;
            opacity: 0;
          }
          
          .button-78:active:not(:disabled) {
            color: #ccc;
          }
          
          .button-78:active:not(:disabled):before {
            background-image: linear-gradient(0deg, rgba(0, 0, 0, .2), rgba(0, 0, 0, .2)), linear-gradient(92.83deg, #ff7426 0, #f93a13 100%);
          }
          
          .button-78:active:not(:disabled):after {
            background-image: linear-gradient(#541a0f 0, #0c0d0d 100%);
            bottom: 4px;
            left: 4px;
            right: 4px;
            top: 4px;
          }
          
          .button-78:disabled {
            cursor: default;
            opacity: .24;
          }</style>";

          $this->css_3 = "<style>button.button-3 {
            touch-action: manipulation;
            -webkit-appearance: none;
            appearance: none;
            vertical-align: middle;
            color: inherit;
            font: inherit;
            background: transparent;
            padding: 0;
            margin: 0;
            border-radius: 0;
            text-align: inherit;
            text-transform: inherit;
            -webkit-tap-highlight-color: transparent;
          }
          
          button.button-3:focus {
            outline-style: solid;
            outline-color: transparent;
          }
          
          button.button-3 {
            touch-action: manipulation;
            margin: 3px;
            cursor: pointer;
          }
          
          button.button-3 {
            touch-action: manipulation;
            position: relative;
            border: 1px solid #0360df;
            border-radius: 50px;
            padding: 12px 16px;
            background-color: #0360df;
            background-image: radial-gradient(75% 50% at 50% 0%, #f4feff, transparent), radial-gradient(75% 35% at 50% 80%, #8de3fc, transparent);
            box-shadow: inset 0 -2px 4px 1px rgba(17, 110, 231, 0.6), inset 0 -4px 4px 1px #8de3fc, inset 0 0 2px 1px rgba(255, 255, 255, 0.2), 0 1px 4px 1px rgba(17, 110, 231, 0.2), 0 1px 4px 1px rgba(0, 0, 0, 0.1);
            color: #fff;
            text-shadow: 0 1px 1px #116ee7;
            transition-property: border-color, transform, background-color;
            transition-duration: 0.2s;
          }
          button.button-3::after {
            content: '';
            position: absolute;
            top: 1px;
            left: 50%;
            transform: translateX(-50%);
            border-radius: 50px;
            width: 80%;
            height: 40%;
            background-image: linear-gradient(to bottom, #f4feff, transparent);
            opacity: 0.75;
          }
          button.button-3:hover {
            transform: scale(1.04);
          }
          button.button-3:active {
            border-color: #0048d5;
            transform: scale(0.96);
            background-color: #0048d5;
          }</style>";

          $this->css_4 = "<style>.button-18 {
            touch-action: manipulation;
            display: inline-block;
            outline: none;
            font-family: inherit;
            font-size: 1em;
            box-sizing: border-box;
            border: none;
            border-radius: .3em;
            height: 2.75em;
            line-height: 2.5em;
            text-transform: uppercase;
            padding: 0 1em;
            box-shadow: 0 3px 6px rgba(0,0,0,.16), 0 3px 6px rgba(110,80,20,.4),
                        inset 0 -2px 5px 1px rgba(139,66,8,1),
                        inset 0 -1px 1px 3px rgba(250,227,133,1);
            background-image: linear-gradient(160deg, #a54e07, #b47e11, #fef1a2, #bc881b, #a54e07);
            border: 1px solid #a55d07;
            color: rgb(120,50,5);
            text-shadow: 0 2px 2px rgba(250, 227, 133, 1);
            cursor: pointer;
            transition: all .2s ease-in-out;
            background-size: 100% 100%;
            background-position:center;
          }
          .button-18:focus,
          .button-18:hover {
            background-size: 150% 150%;
            box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23),
                          inset 0 -2px 5px 1px #b17d10,
                          inset 0 -1px 1px 3px rgba(250,227,133,1);
            border: 1px solid rgba(165,93,7,.6);
            color: rgba(120,50,5,.8);
          }
          .button-18:active {
            box-shadow: 0 3px 6px rgba(0,0,0,.16), 0 3px 6px rgba(110,80,20,.4),
                        inset 0 -2px 5px 1px #b17d10,
                          inset 0 -1px 1px 3px rgba(250,227,133,1);
          }</style>";


          $this->css_5 = "<style>.bn29 {
            border: none;
            padding: 0.8em 2.5em;
            outline: none;
            color: white;
            font-style: 1.2em;
            position: relative;
            z-index: 1;
            cursor: pointer;
            background: none;
            text-shadow: 3px 3px 10px rgba(0, 0, 0, 0.45);
          }
          
          .bn29:before,
          .bn29:after {
            position: absolute;
            top: 50%;
            left: 50%;
            border-radius: 10em;
            -webkit-transform: translateX(-50%) translateY(-50%);
            transform: translateX(-50%) translateY(-50%);
            width: 105%;
            height: 105%;
            content: '';
            z-index: -2;
            background-size: 400% 400%;
            background: linear-gradient(
              60deg,
              #f79533,
              #f37055,
              #ef4e7b,
              #a166ab,
              #5073b8,
              #1098ad,
              #07b39b,
              #6fba82
            );
          }
          
          .bn29:before {
            -webkit-filter: blur(7px);
            filter: blur(7px);
            -webkit-transition: all 0.25s ease;
            transition: all 0.25s ease;
            -webkit-animation: pulse 10s infinite ease;
            animation: pulse 10s infinite ease;
          }
          
          .bn29:after {
            -webkit-filter: blur(0.3px);
            filter: blur(0.3px);
          }
          
          .bn29:hover:before {
            width: 115%;
            height: 115%;
          }</style>";



          $this->css_6 = "<style>.bn632-hover {
            width: 160px;
            font-size: 16px;
            font-weight: 600;
            color: #fff;
            cursor: pointer;
            margin: 20px;
            height: 55px;
            text-align: center;
            border: none;
            background-size: 300% 100%;
            border-radius: 50px;
            -o-transition: all 0.4s ease-in-out;
            -webkit-transition: all 0.4s ease-in-out;
            transition: all 0.4s ease-in-out;
          }
          
          .bn632-hover:hover {
            background-position: 100% 0;
            moz-transition: all .4s ease-in-out;
            -o-transition: all .4s ease-in-out;
            -webkit-transition: all .4s ease-in-out;
            transition: all .4s ease-in-out;
          }
          
          .bn632-hover:focus {
            outline: none;
          }
          
          .bn632-hover.bn24 {
            background-image: linear-gradient(
                to right,
                #6253e1,
                #852d91,
                #a3a1ff,
                #f24645
              );
            box-shadow: 0 4px 15px 0 rgba(126, 52, 161, 0.75);
          }</style>";


          $this->css_7 = "<style>.bn632-hover {
            width: 160px;
            font-size: 16px;
            font-weight: 600;
            color: #fff;
            cursor: pointer;
            margin: 20px;
            height: 55px;
            text-align:center;
            border: none;
            background-size: 300% 100%;
            border-radius: 50px;
            moz-transition: all .4s ease-in-out;
            -o-transition: all .4s ease-in-out;
            -webkit-transition: all .4s ease-in-out;
            transition: all .4s ease-in-out;
          }
          
          .bn632-hover:hover {
            background-position: 100% 0;
            moz-transition: all .4s ease-in-out;
            -o-transition: all .4s ease-in-out;
            -webkit-transition: all .4s ease-in-out;
            transition: all .4s ease-in-out;
          }
          
          .bn632-hover:focus {
            outline: none;
          }
          
          .bn632-hover.bn20 {
            background-image: linear-gradient(
              to right,
              #667eea,
              #764ba2,
              #6b8dd6,
              #8e37d7
            );
            box-shadow: 0 4px 15px 0 rgba(116, 79, 168, 0.75);
          }</style>";


          $this->css_8 = "<style>.bn5 {
            padding: 0.6em 2em;
            border: none;
            outline: none;
            color: rgb(255, 255, 255);
            background: #111;
            cursor: pointer;
            position: relative;
            z-index: 0;
            border-radius: 10px;
          }
          
          .bn5:before {
            content: '';
            background: linear-gradient(
              45deg,
              #ff0000,
              #ff7300,
              #fffb00,
              #48ff00,
              #00ffd5,
              #002bff,
              #7a00ff,
              #ff00c8,
              #ff0000
            );
            position: absolute;
            top: -2px;
            left: -2px;
            background-size: 400%;
            z-index: -1;
            filter: blur(5px);
            width: calc(100% + 4px);
            height: calc(100% + 4px);
            animation: glowingbn5 20s linear infinite;
            opacity: 0;
            transition: opacity 0.3s ease-in-out;
            border-radius: 10px;
          }
          
          @keyframes glowingbn5 {
            0% {
              background-position: 0 0;
            }
            50% {
              background-position: 400% 0;
            }
            100% {
              background-position: 0 0;
            }
          }
          
          .bn5:active {
            color: #000;
          }
          
          .bn5:active:after {
            background: transparent;
          }
          
          .bn5:hover:before {
            opacity: 1;
          }
          
          .bn5:after {
            z-index: -1;
            content: '';
            position: absolute;
            width: 100%;
            height: 100%;
            background: #191919;
            left: 0;
            top: 0;
            border-radius: 10px;
          }</style>";




    }







    public function addButtonOrange($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='orange-button'>$text</button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='orange-button'>$text</button>";
        }else{
            $this->buttons .= "<button type='button' class='orange-button'>$text</button>";
        }
    }

    public function addButtonGreenlight($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='button-63'>$text</button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='button-63'>$text</button>";
        }else{
            $this->buttons .= "<button type='button' class='button-63'>$text</button>";
        }
    }
    public function addButtonShadowOrange($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='button-78'>$text</button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='button-78'>$text</button>";
        }else{
            $this->buttons .= "<button type='button' class='button-78'>$text</button>";
        }
    }

    public function addButtonShadowOrangeA($text, $lien){
          $this->buttons .= "<a type='button' class='button-78' href='$lien' target='_blank' rel='noopener noreferrer'>$text</a>";
    }

    public function addButtonnjesenberger($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='button-3'><span class='text'>$text</span></button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='button-3'><span class='text'>$text</span></button>";
        }else{
            $this->buttons .= "<button type='button' class='button-3'><span class='text'>$text</span></button>";
        }
    }
    

    public function addButtonkvasheilds($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button  type='submit' class='button-18'><span class='text'>$text</span></button>";
        }else if($type == "reset"){
            $this->buttons .= "<button  type='reset' class='button-18'><span class='text'>$text</span></button>";
        }else{
            $this->buttons .= "<button  type='button' class='button-18'><span class='text'>$text</span></button>";
        }
    }


    public function addButtoncssbuttonsio($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='bn29'>$text</button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='bn29'>$text</button>";
        }else{
            $this->buttons .= "<button type='button' class='bn29'>$text</button>";
        }
    }

    public function addButtonPurpleShow($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='bn632-hover bn24'>$text</button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='bn632-hover bn24'>$text</button>";
        }else{
            $this->buttons .= "<button type='button' class='bn632-hover bn24'>$text</button>";
        }
    }


    public function addButtonPurpleShow2($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='bn632-hover bn20'>$text</button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='bn632-hover bn20'>$text</button>";
        }else{
            $this->buttons .= "<button type='button' class='bn632-hover bn20'>$text</button>";
        }
    }

    public function addButtonMulti($text, $type = "button"){
        if ($type == "submit"){
            $this->buttons .= "<button type='submit' class='bn5'>$text</button>";
        }else if($type == "reset"){
            $this->buttons .= "<button type='reset' class='bn5'>$text</button>";
        }else{
            $this->buttons .= "<button type='button' class='bn5'>$text</button>";
        }
    }






    public function renderButtonsOrange(){
        return $this->css . $this->buttons;
    }
    public function renderButtonsGreenlight(){
        return $this->css_1 . $this->buttons;
    }

    public function renderButtonsShadowOrange(){
        return $this->css_2 . $this->buttons;
    }

    public function renderButtonsShadowOrangeA(){
      return $this->css_2 . $this->buttons;
  }

    public function renderButtonsnjesenberger(){
        return $this->css_3 . $this->buttons;
    }

    public function renderButtonskvasheilds(){
        return $this->css_4 . $this->buttons;
    }

    public function renderButtonscssbuttonsio(){
        return $this->css_5 . $this->buttons;
    }

    public function renderButtonsPurpleShow(){
        return $this->css_6 . $this->buttons;
    }

    public function renderButtonsPurpleShow2(){
        return $this->css_7 . $this->buttons;
    }

    public function renderButtonsMulti(){
        return $this->css_8 . $this->buttons;
    }

}


/*
Example d'utilisation de la class ButtonGenerator


            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonkvasheilds("Envoyer", "submit");
            echo $buttonGen->renderButtonskvasheilds();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonMulti("Envoyer", "submit");
            echo $buttonGen->renderButtonsMulti();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonGreenlight("Envoyer", "submit");
            echo $buttonGen->renderButtonsGreenlight();


            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtoncssbuttonsio("Envoyer", "submit");
            echo $buttonGen->renderButtonscssbuttonsio();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonnjesenberger("Envoyer", "submit");
            echo $buttonGen->renderButtonsnjesenberger();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonOrange("Envoyer", "submit");
            echo $buttonGen->renderButtonsOrange();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonPurpleShow("Envoyer", "submit");
            echo $buttonGen->renderButtonsPurpleShow();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonPurpleShow2("Envoyer", "submit");
            echo $buttonGen->renderButtonsPurpleShow2();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonShadowOrange("Envoyer", "submit");
            echo $buttonGen->renderButtonsShadowOrange();

            $buttonGen = new ButtonGenerator();
            $buttonGen->addButtonShadowOrangeA("Envoyer", "https://...");
            echo $buttonGen->renderButtonsShadowOrangeA();

*/