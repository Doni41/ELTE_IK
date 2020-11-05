const inputField = document.querySelector('input');
const fieldArray = []

inputField.addEventListener('keydown', e => {
    e.preventDefault();
    if(e.key == 'Backspace' || e.key == 'Delete') {
        return;
    }

    const value = e.key;

    if(value.match("[0-9\.]")) {
        console.log(inputField.value);
        console.log('+');
        console.log(value);
        inputField.value += value
    }

    if(inputField.value.match("^[0-9]{1,3}[\.]{1}[0-9]{1,3}[\.]{1}[0-9]{1,3}[\.]{1}[0-9]{1,3}$")) {
        inputField.classList.toggle('helyes');
    } else {
        inputField.classList.toggle('helytelen');
    }
});


// /^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/

/*
if (/^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/.test(inputField.value)) {
            inputField.classList.toggle('helyes');
        } else if (!(inputField.classList.contains('helytelen'))) {
            inputField.classList.toggle('helytelen');
        } 
*/

/* Z


input.addEventListener("keydown", function (event) {
    event.preventDefault()
    if (event.key === 'Backspace' || event.key === 'Delete') {
        return
    }
    const value=event.key

    if(value.match("[0-9\.]")){
        input.value+=value
    }
    if(input.value.match("^[0-9]{1,3}[\.]{1}[0-9]{1,3}[\.]{1}[0-9]{1,3}[\.]{1}[0-9]{1,3}$")){
        input.classList.add("helyes")
        input.classList.remove("helytelen")
    }else{
        input.classList.add("helytelen")
        input.classList.remove("helyes")
    }

})
*/