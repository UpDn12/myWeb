'use strict'
//BOM   Browser Object Mode
function getBOM(){
//tamanio de la ventada del brouser
console.log(window.innerHeight);
console.log(window.innerWidth);
//informacion de la pag
console.log(window.location);
/*parametros de .location.
host: "127.0.0.1:5500"
hostname: "127.0.0.1"
href: "http://127.0.0.1:5500/index.html"
origin: "http://127.0.0.1:5500"
pathname: "/index.html"
port: "5500"
protocol: "http:" */
}
function redirect(url){
    window.location.href=url;
}
function abrirWindows(url){
    window.open(url,"width=300","height=500");
}
