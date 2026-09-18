function calcularMedia() {
    let nome = document.getElementById("nomeAluno").value;

    let nota1 = Number(document.getElementById("nota1").value);
    
    let nota2 = Number(document.getElementById("nota2").value);

    let media = (nota1 + nota2) / 2;

    if (media >= 7) {
        document.getElementById("resultado").innerHTML=nome+" Foi Aprovado!<br>"+"Média:"+media.toFixed(1);

    }
    else{
        document.getElementById("resultado").innerHTML=nome+" Foi Reprovado! Tente outra vez.<br>"+"Média:"+media.toFixed(1);
    }
}

