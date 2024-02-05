// TODO: Add code to check answers to questions
document.addEventListener("DOMContentLoaded", function() {
    let correct = document.querySelector(".correct");
    correct.addEventListener("click", function() {
        correct.style.backgroundColor = "green";
        document.querySelector("#answer1").innerHTML = "Correct!";
    });

    let incorrects = document.querySelectorAll(".incorrect");
    for(let i=0; i < incorrects.length; i++){
        incorrects[i].addEventListener("click", function() {
        incorrects[i].style.backgroundColor = "red";
        document.querySelector("#answer1").innerHTML = "Incorrect!";
     });
    }

    document.querySelector('#submit').addEventListener("click", function() {
        let free_response = document.querySelector("input");
        if(free_response.value == "Winston Churchill"){
            free_response.style.backgroundColor = "green";
            document.querySelector("#answer2").innerHTML = "Correct! Very good.";
        } else{
            free_response.style.backgroundColor = "red";
            document.querySelector("#answer2").innerHTML = "Incorrect, try again.";

        }
    });
 });