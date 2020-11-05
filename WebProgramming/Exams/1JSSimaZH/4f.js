// Query selectors
const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');
const bigMacButtonIncrease = document.querySelector('#BigMacIncrease');
const bigMacButtonDecrease = document.querySelector('#BigMacDecrease');
const spotifyButtonIncrease = document.querySelector('#SpotifyIncrease');
const spotifyButtonDecrease = document.querySelector('#SpotifyDecrease');

let BigMac = {
    x: 0,
    y: (600 - 250),
    previousMac: (600 - 250),
}
console.log('Fuggvenyen kivul:' ,BigMac.x, ' , ' , BigMac.y);

let Spotify = {
    x: 0,
    y: (600 - 300),
    previousSpotify: 300,
}

let seged = {
    x: 0,
    y: 0,
}

ctx.lineWidth = 5;

function moveToElements (x, y, velocityX, velocityY, color) {
        ctx.strokeStyle = color;
        ctx.beginPath();
        ctx.moveTo(x, y);
        seged.x = x + velocityX;
        seged.y = y + velocityY;
        ctx.lineTo(seged.x, seged.y);
        ctx.closePath();
        ctx.stroke();
        return seged;
};

// BigMac increase
bigMacButtonIncrease.addEventListener('click', () => {
    const previousPrice = BigMac.y;
    moveToElements(BigMac.x, BigMac.y, 10, -10, 'red');
    BigMac.x = seged.x
    BigMac.y = seged.y

    const writeValue = (BigMac.previousMac === BigMac.y);
    BigMac.previousMac = previousPrice;
    if(writeValue) {
        ctx.fillStyle = 'red'
        ctx.fillText(previousPrice, BigMac.x, previousPrice);
    }
}); 

// BigMac decrease
bigMacButtonDecrease.addEventListener('click', () => {
    const previousPrice = BigMac.y;
    moveToElements(BigMac.x, BigMac.y, 10, 10, 'red');
    BigMac.x = seged.x
    BigMac.y = seged.y

    const writeValue = (BigMac.previousMac === BigMac.y);
    BigMac.previousMac = previousPrice;
    if(writeValue) {
        ctx.fillStyle = 'red'
        ctx.fillText(previousPrice, BigMac.x, previousPrice);
    }
}); 

// Spotify increase
spotifyButtonIncrease.addEventListener('click', () => {
    const previousPrice = Spotify.y;
    moveToElements(Spotify.x, Spotify.y, 10, -10, 'green');
    Spotify.x = seged.x
    Spotify.y = seged.y

    const writeValue = (Spotify.previousSpotify === Spotify.y);
    Spotify.previousSpotify = previousPrice;
    if(writeValue) {
        ctx.fillStyle = 'green'
        ctx.fillText(previousPrice, Spotify.x, previousPrice);
    }
});

// Spotify decrease
spotifyButtonDecrease.addEventListener('click', () => {
    const previousPrice = Spotify.y;
    moveToElements(Spotify.x, Spotify.y, 10, 10, 'green');
    Spotify.x = seged.x
    Spotify.y = seged.y

    const writeValue = (Spotify.previousSpotify === Spotify.y);
    Spotify.previousSpotify = previousPrice;
    if(writeValue) {
        ctx.fillStyle = 'green'
        ctx.fillText(previousPrice, Spotify.x, previousPrice);
    }
});