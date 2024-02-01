document.querySelector('form').addEventListener('submit', function(event) {
    alert('Hello, ' + document.querySelector('#name').value);
    event.preventDefault();
});