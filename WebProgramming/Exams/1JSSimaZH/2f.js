// Query selectors
const datas = document.querySelector('#adatok');
const firstList = document.querySelectorAll('li.szallitmany:nth-of-type(1)');
const secondList = document.querySelectorAll('li.szallitmany:nth-of-type(2)');
const thirdList = document.querySelectorAll('li.szallitmany:nth-of-type(3)');

// Event listeners
datas.addEventListener('click', function(e) {
    // console.log(document.querySelector('li.szallitmany:nth-child(1) > div:nth-of-type(3)'));
    //console.log(document.querySelector('li.szallitmany:nth-child(1)'));

    /* Elso li.szallitmany */
    // Elso div -> minden .erkezes osztalyu lesz
    if (e.target.matches('li.szallitmany:nth-child(1) > div:nth-child(1)')) {
        for( let i = 0; i < firstList.length; i++) {
            firstList[i].classList.toggle('erkezes');
        }
    }

    // Masodik div -> minden .polc osztalyu lesz
    if (e.target.matches('li.szallitmany:nth-child(1) > div:nth-of-type(3)')) {
        for( let i = 0; i < firstList.length; i++) {
            firstList[i].classList.toggle('polc');
        }
    }

    // li-k div -> div-ek .erkezes osztalyuak lesznek
    if (e.target.matches('li.szallitmany:nth-child(1) li')) {
        e.target.classList.toggle('termek');
    }


    /* Masodik li.szallitmany */
    // Maosdik div -> minden .erkezes osztalyu lesz
    if (e.target.matches('li.szallitmany:nth-of-type(2) > div:nth-of-type(1)')) {
        for( let i = 0; i < secondList.length; i++) {
            secondList[i].classList.toggle('erkezes');
        }
    }

    // Masodik div -> minden .polc osztalyu lesz
    if (e.target.matches('li.szallitmany:nth-child(2) > div:nth-of-type(3)')) {
        for( let i = 0; i < secondList.length; i++) {
            secondList[i].classList.toggle('polc');
        }
    }

    // li-k div -> div-ek .erkezes osztalyuak lesznek
    if (e.target.matches('li.szallitmany:nth-child(2) li')) {
        e.target.classList.toggle('termek');
    }


  /* Harmadik li.szallitmany */
    // Elso div -> minden .erkezes osztalyu lesz
    if (e.target.matches('li.szallitmany:nth-child(3) > div:nth-child(1)')) {
        for( let i = 0; i < thirdList.length; i++) {
            thirdList[i].classList.toggle('erkezes');
        }
    }

    // Masodik div -> minden .polc osztalyu lesz
    if (e.target.matches('li.szallitmany:nth-child(3) > div:nth-of-type(3)')) {
        for( let i = 0; i < thirdList.length; i++) {
            thirdList[i].classList.toggle('polc');
        }
    }

    // li-k div -> div-ek .erkezes osztalyuak lesznek
    if (e.target.matches('li.szallitmany:nth-child(3) li')) {
        e.target.classList.toggle('termek');
    }
});