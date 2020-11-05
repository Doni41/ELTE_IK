const bodyMine = document.querySelector('body');
const generateButton = document.querySelector('button');
const divHTML = document.querySelector('#maindiv');
const h1S = document.querySelectorAll('div > *');

generateButton.addEventListener('click', () => {
    let newDiv = document.createElement('div');
    if (document.querySelector('#toc')) {
        console.log('mar letezik!');
    } else {
        newDiv.setAttribute('id', 'toc');
        bodyMine.insertBefore(newDiv, generateButton);
    }
    
    for (let index = 0; index < h1S.length; index++) {
        if (h1S[index].nodeName === 'H1') {
            newDiv.innerHTML += `<ul><li>${h1S[index].innerText}</li></ul>`;
        }
        if (h1S[index].nodeName == 'H2') {
            newDiv.innerHTML += `<ul><ul><li>${h1S[index].innerText}</li></ul></ul>`
        }
        if (h1S[index].nodeName == 'H3') {
            newDiv.innerHTML += `<ul><ul><ul><li>${h1S[index].innerText}</li></ul></ul></ul>`
        }
        if (h1S[index].nodeName == 'H4') {
            newDiv.innerHTML += `<ul><ul><ul><ul><li>${h1S[index].innerText}</li></ul></ul></ul></ul>`
        }        
    }
});