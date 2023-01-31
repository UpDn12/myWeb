'use strict'



//Evento LOUD ejecuta cuadno la paguina esta cargada *******************************
window.addEventListener('load', function(){
    //EVENTOS DEL RATON     ////////////////////////////////////////////////////////
        function cambiarColor() {
            var bg=boton.style.background;
            if(bg=="green"){
                boton.style.background="red";
            }else{
                boton.style.background="green";
            }
            boton.style.padding="10px";
            boton.style.border="1px solid #ccc";
        return true;}

    
        var boton=document.querySelector("#stop");

        //event Click
        boton.addEventListener('dblclick', function(){
            cambiarColor();
        });

        //mouse Over pasar el mouse sobre
        boton.addEventListener('mouseover', function(){
            boton.style.background="white"
        })

        //mouseOut salir con el mause sobre
        boton.addEventListener('mouseout',function(){
            boton.style.background="#ccc";
        })

    //EVENTOS DEL TECLADO   /////////////////////////////////////////////////////////////
        var input=document.querySelector("#campoNombre");
        //focus sabe si estas dento del Imput
        input.addEventListener('focus', function(){
            console.log("estas dentro del inout");
        })

        //blur sabe si estas fuera del input(se activa primero entrando al input)
        input.addEventListener('blur', function(){
            console.log('estas fuera del input');
        })

        //KeyDown sabe si estas precionando una letra [String.fromCharCode(event.keyCode)] que tecla se pulsa
        input.addEventListener('keydown', function(){
            console.log('estas pulsando esta tecla', String.fromCharCode(event.keyCode));
        })

        //KeyPess
        input.addEventListener('keypress', function(){
            console.log('tecla presionada');
        })

        //keyUp sabe cuando dejas de presionar una tecla
        input.addEventListener('keyup', function(){
            console.log('tecla suelta');
        })

    //TIME ejecuta un a cion en un intermavo de time //////////////////////////////
        function intervalo(){
            var tiempo=setInterval(function(){
                console.log("Set interval Ejecutando");
                
                var encabezado=document.querySelector("h1");
                if (encabezado.style.fontSize=="50px") {
                    encabezado.style.fontSize="20px";
                } else {
                    encabezado.style.fontSize="50px";
                }
                
            },1000);
            return tiempo;
        }
        var tiempo=intervalo();
    //TIMEOut ejecuta una acion una sola vez en x tiempo
        /*var timeOut=setTimeout(function(){
            console.log("Set TIME Out Ejecutando");
            var encabezado=document.querySelector("h1");
            encabezado.style.background="green";
        },1000);*/

    //STOP detiene un intervalo
        var stop=document.querySelector("#stop");
        stop.addEventListener("click", function(){
            alert("paraste el intevalo");
            clearInterval(tiempo);
        });

    //Start comienza un intervalo
        var start=document.querySelector("#start");
        start.addEventListener('click', function(){
            alert("iniciado intervalo");
            intervalo();
        });
});