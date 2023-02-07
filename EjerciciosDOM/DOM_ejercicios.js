'use strict'

window.addEventListener('load', function(){
    console.log("DOM");

    var form=document.querySelector("#form");
    var box_dashed=document.querySelector(".dashed");
    //oculata el cuadro hasta aplastar send
    box_dashed.style.display="none";

    //evento al aplastar send
    form.addEventListener("submit", function(){
        console.log("event submit ");
        //recolecta los datos del input
        var name=document.querySelector("#name").value;
        var lastname=document.querySelector("#lastname").value;
        var age=document.querySelector("#age").value;
        //hace visible el cuadra despues de apllastar send
        box_dashed.style.display="block";
        //crear los datos
        // span, selecionan tampian el span del html ej:"Name: <span></span>""
        var p_name=document.querySelector("#p_name span");
        var p_lastname=document.querySelector("#p_lastname span");
        var p_age=document.querySelector("#p_age span");
        //agrega datos al html done esta el  "<span></span>"
        p_name.innerHTML=name;
        p_lastname.innerHTML=lastname;
        p_age.innerHTML=age;
        /*
        var user_data=[name, lastname, age];
        var indice;
        for(indice in user_data){
            var parf=document.createElement("p");
            parf.append(user_data[indice]);
            box_dashed.append(parf);
        }
        */
        
    })
});