// Query selectors
const downloadSpeed = document.querySelector('#downloadspeed');
const downloadButton = document.querySelector('#downloading');
const fileSize = document.querySelectorAll('td:nth-child(2)');
const fileDownloaded = document.querySelectorAll('td:nth-child(3)');
const tableOfContext = document.querySelector('tbody');

// Containers
const actuals = [];
const news = [];

// Event listeners
downloadButton.addEventListener('click', function() {
    for (let i = 0; i< fileSize.length; i++) {
    
        actuals[i] = parseFloat(fileDownloaded[i].innerText);                 // %
        console.log(fileSize[i].innerText);
        console.log(fileDownloaded[i].innerText);
        news[i] = (downloadSpeed.value / (parseFloat(fileSize[i].innerText))) * 100;  // %

        if ((news[i] + actuals[i]) > 100) {
            fileDownloaded[i].innerHTML = `<tb>100%</tb>`      
        } else {
            fileDownloaded[i].innerHTML = `<tb>${(actuals[i] + news[i])}%</tb>`;   
        }
    }
});



