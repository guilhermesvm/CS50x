document.addEventListener('DOMContentLoaded', function(){
    document.querySelector('form').addEventListener('submit', function(e) {
        alert('Hello, ' + document.querySelector('#name').value); 
    });
})