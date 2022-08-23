function CalcularMedia()
{
    var n1, n2, n3, media;
    var nome= document.getElementById("idNome").value;
    n1= Number(document.getElementById("idNota1").value)
    n2= Number(document.getElementById("idNota2").value)
    n3= Number(document.getElementById("idNota3").value)
    media= (n1+n2+n3)/3
    document.getElementById("idMedia").value =  nome+ "  "+ media.toFixed(2)
}

function Validar()
{
    var n1= Number(document.getElementById("idNota1").value)
    if (n1 <0 || n1 > 10)
    {
        window.alert("Nota inválida")
    }
}