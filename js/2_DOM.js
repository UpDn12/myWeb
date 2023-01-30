'use strict'
//DOM Document Object Model


//Conseguir elemento con un Id concreto
function DivIdConcreto(){
var caja=document.getElementById("miCaja");
var caja1=document.querySelector("#miCaja");

caja.innerHTML="Soy Me cajas";  //cambia el contenido
caja.style.background="green";  //cambia el background
caja.style.padding="20px";      //cambia el padding
caja.style.color="white";       //cambia el color de letra
caja.className="clase Caja";    //aniadir a clase
}

//conseguir elemento por su etiqueta
function DivEtiqueta(){
var TodosLosDvis=document.getElementsByTagName('div');
TodosLosDvis[0].innerHTML="laptm";
console.log(contenidoEnTxt);
}

//conseguir elemento por su clase
var divRojos=document.getElementsByClassName('rojo');
//pinta cada div con la clase rojo
for (var i in divRojos) {
    if (divRojos[i].className=="rojo") {
        divRojos[i].style.background="gray";
    }
}
console.log(divRojos);
