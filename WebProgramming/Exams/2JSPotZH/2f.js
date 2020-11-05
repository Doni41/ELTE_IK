// Query selectors
const showButton = document.querySelector('button');
const hiddenElements = document.querySelectorAll('td[data-hidden="true"]')
const elementAll = document.querySelector('table');
const nameField = document.querySelector('#name');
const symbolField = document.querySelector('#symbol');
const numberField = document.querySelector('#number');
const fields = document.querySelectorAll('table td[id]');

// containers + new array
const hiddenOriginaly = []
let colors = [];
let counter = 0;
let elem = [];

hiddenElements.forEach(e => hiddenOriginaly.push(e));

// Event listener
showButton.addEventListener('click', () => {
    for (let i = 0; i < hiddenOriginaly.length; i++) {
        if (hiddenOriginaly[i].getAttribute('data-hidden') === 'true') {
            hiddenOriginaly[i].toggleAttribute('data-hidden')
        } else {
            hiddenElements[i].setAttribute('data-hidden', 'true');
        }
    }
});

elementAll.addEventListener('click', (e) => {

    if (e.target.matches('td')) {
        if(counter === 0) {
        elem.push(e.target);
        colors.push(e.target.style.backgroundColor);
        elem[counter].style.backgroundColor = 'red';
        counter++;
        }   else {
                if (elem[counter - 1] !== e.target) {
                    elem[counter - 1].style.backgroundColor = colors[counter - 1]
                    elem.push(e.target);
                    colors.push(e.target.style.backgroundColor);
                    elem[counter].style.backgroundColor = 'red';
                    counter++;
                }
            }
        
        symbolField.innerHTML = e.target.getAttribute('id');
        nameField.innerHTML = e.target.getAttribute('data-name');
        for (let i = 0; i < fields.length; i++) {
            if (e.target.getAttribute('id') === fields[i].getAttribute('id')) {
                numberField.innerHTML = (i + 1);
            }
        }
        
    }
});