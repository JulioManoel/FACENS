function calcular(){
    var peso = Number(document.getElementById("idPeso").value);
    var altura = Number(document.getElementById("idAltura").value);
    document.getElementById("text").innerHTML= "IMC = " + (peso/(altura*altura));   
}

