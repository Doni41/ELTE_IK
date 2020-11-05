const canvas = document.querySelector('canvas');
const context = canvas.getContext('2d');

// State
let starship = {
    x: (canvas.width- 30) / 2,
    y: canvas.height-60,
    width: 46,
    height: 62,
    vx: 100,    // px/s
    dir: 0
}

let asteroids = []

let gameState = 'INGAME';    // 'END' or not

let counter = 0;

const images = {
    background: new Image (),
    starship: new Image (),
    asteroid: new Image (),
    explosion: new Image (),
}
images.background.src = 'background.png';
images.starship.src = 'mille.png';
images.asteroid.src = 'asteroids.png';
images.explosion.src = 'explosion.png';

// Helper function
// Random number generator
function random(a, b) {
    // Math.random() -> 0 es 1 kozott egy random lebegopontos szamot allit elo
    return Math.floor(Math.random() *  (b - a + 1)) + a;
}

// Collison detection
function isCollison(r1, r2) {
    return !(
        r2.y + r2.height < r1.y ||
        r2.x > r1.x + r1.width ||
        r2.y > r1.y + r1.height ||
        r2.x + r2.width < r1.x
    )
}

// Game Loop
let lastTime = performance.now();   // oldal betoltese ota eltet ido
function gameLoop(now = performance.now()) {
    // oldal betoltese ota eltet ido, ezzel az egyseges mozgast biztositjuk
    const dt = (now - lastTime) / 1000;
    lastTime = now;
    // merni kell az eltelt idot, hogy minden eszkozon ugyan ugy rajzolja ujra
    update(dt);
    draw();
    if (gameState !== 'END') {
        window.requestAnimationFrame(gameLoop);
    }
    
}

function update(dt) {
    // Starhsip
    starship.x += starship.dir * starship.vx * dt; // ds = v * dt

    // New asteroids
    if (Math.random() < 0.03) {
        asteroids.push(

        {
            x: random(0, canvas.width),
            y: -50,
            width: random(30, 50),
            height: random(30, 50),
            vx: random(-20, 20),
            vy: random(50, 120)
        }
        )}
    
    // Move Asteroids
    asteroids.forEach(asteroids => {
        asteroids.x += asteroids.vx * dt;
        asteroids.y += asteroids.vy * dt;

        if (isCollison (starship, asteroids)) {
            gameState = 'END';
        }
    }) 

    // Delete asteroids
    const before = asteroids.length;
    asteroids = asteroids.filter(asteroids => asteroids.y < canvas.height);
    const after = asteroids.length;
    if (gameState !== 'END') {
        counter += before - after;
    }
    
}

function draw() {
    // Background
        // clearRect letorlo a 0,0 ponttol a canvast
    // context.clearRect(0, 0, canvas.width, canvas.height);
    context.drawImage (images.background, 0, 0, canvas.width, canvas.height);

    // Starship
    context.fillStyle = gameState === 'INGAME' ? 'orange' : 'red';
    if (gameState !== 'END') {
        context.drawImage(images.starship, starship.x, starship.y, starship.width, starship.height);    
    } else {
        context.drawImage(images.explosion,
             552, 0, 184, 184,
             starship.x, starship.y, starship.width, starship.height);    
    }
    //context.fillRect(starship.x, starship.y, starship.width, starship.height);
    context.drawImage(images.starship, starship.x, starship.y, starship.width, starship.height);

    // Asteroid
    context.fillStyle = 'brown';
    asteroids.forEach(asteroids => {
        // context.fillRect(asteroids.x, asteroids.y, asteroids.width, asteroids.height)
        context.drawImage(images.asteroid,
            0, 36, 72, 72,
            asteroids.x, asteroids.y, asteroids.width, asteroids.height)
    })

    // Counter
    context.fillStyle = 'white';
    context.font = '25px Courier New';
    context.fillText(`Points : ${counter}`, 10, 30)

    // The end
    if (gameState === 'END') {
        context.fillStyle = 'white';
        context.font = '100px Courier New';
        context.fillText ('The End', 75, 200);
    }
}

gameLoop()

// Event listeners
    // jobbra - balra mozasok

document.addEventListener('keydown', onKeyDown);
document.addEventListener('keyup', onKeyUp);

function onKeyDown(e) {
    if (e.key === 'ArrowLeft') {
        starship.dir = -1;
    }

    if (e.key === 'ArrowRight') {
        starship.dir = 1;
    }
}

function onKeyUp(e) {
    starship.dir = 0;
}