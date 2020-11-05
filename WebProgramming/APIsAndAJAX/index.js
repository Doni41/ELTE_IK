// const APIKEY = ''    // your API key

let favourites = []
let selectedMovie = null

const txtSearch = document.querySelector('#txtSearch')
const btnSearch = document.querySelector('#btnSearch')
const searchResultsList = document.querySelector('#search-results')
const favouritesList = document.querySelector('#favourites')
const details = document.querySelector('#details')
    

btnSearch.addEventListener('click', onSearch)
function onSearch(e) {
    const title = txtSearch.value

    // http://www.omdbapi.com/?apikey=2dd0dbee&s=hobbit
    const xhr = new XMLHttpRequest()
    xhr.addEventListener('load', onLoad)
    // meg lehet adni neki a sajat API kulcsunkat is `..?apikey=£{APIKEY}
    xhr.open('GET', `http://www.omdbapi.com/?apikey=${APIKEY}&s=${title}`)
    xhr.responseType = 'json'
    xhr.send() 
}

function onLoad(e) {
    // this itt ahhoz tartozik, akihez fel van veve (xhr)
    const searchResults = this.response.Search

    searchResultsList.innerHTML = genSearchResultsList(searchResults, favourites)
}

// Delegate to the checkbox
searchResultsList.addEventListener('click', onCheck)
async function onCheck(e) {
    if (e.target.matches('input[type="checkbox"]')) {
        // looking for the imdbID of the li element from DOM 
        const li = e.target.closest('li')
        // imdbid from the dataset (html -> data-imdbid)
        const imdbID = li.dataset.imdbid
        if (e.target.checked) {
            // is the movie already exists in favlist
            const fmovie = favourites.find(movie => movie.imdbID == imdbID)
            if (fmovie) {
                fmovie.deleted = false
            } else {
                // fetch API - async function, return with a promise
                const response = await fetch(`http://www.omdbapi.com/?apikey=${APIKEY}&i=${imdbID}`)
                const movie = await response.json()
                movie.deleted = false
                // add to the favourites
                favourites.push(movie)
            }
            // favouritesList.innerHTML = genFavouritesList(favourites)
        } else {
            const fmovie = favourites.find(movie => movie.imdbID == imdbID)
            fmovie.deleted = true
        }
        // save favourites
        saveFavourites(favourites)
        showFavourites()
    } 
}

// Save favourites
function saveFavourites(favourites) {
    localStorage.setItem('my-favourite-movies', JSON.stringify(favourites))
}

// Load favourites
function loadFavourites() {
    // Defaulting with empty array
    favourites = JSON.parse(localStorage.getItem('my-favourite-movies')) || []
}


// Favourite 
favouritesList.addEventListener('click', onFavouriteClick)
function onFavouriteClick(e) {
    if (e.target.matches('li')) {
        const imdbID = e.target.dataset.imdbid
        const movie = favourites.find(movie => movie.imdbID == imdbID)
        selectedMovie = movie
        showSelectedMovie()
    }
    
}

// Add new comment
details.addEventListener('click', onComment)
function onComment(e) {
    if (e.target.matches('#details button')) {
        const text = this.querySelector('textarea').value
        selectedMovie.comments.push({
            created: Date.now(),
            text,
        })
        saveFavourites(favourites)
        showSelectedMovie()
    }
}

// Show favourites
function showFavourites() {
    const notDeletedFavourites = favourites.filter(m => !m.deleted)
    favouritesList.innerHTML = genFavouritesList(notDeletedFavourites)
}

function showSelectedMovie() {
    details.innerHTML = genDetails(selectedMovie)
}

// HTML generators
function genSearchResultsList(list, favourites) {
    // the return value is an array -> join() method
    // checkbox is already checked or not 
    return list.map(movie => `
    <li data-imdbid="${movie.imdbID}">
        <input type="checkbox" ${favourites.some(fmovie => !fmovie.deleted && fmovie.imdbID === movie.imdbID ? 'checked' : '')}>
        <img src="${movie.Poster}">
        <a href="https://www.imdb.com/title/${movie.imdbID}/">${movie.Title} (${movie.Year})
    </li>
    `).join('')   
}

function genFavouritesList(list) {
    return list.map(movie => `
        <li data-imdbid="${movie.imdbID}">
        ${movie.Title} (${movie.Year})
        </li>
    `).join('')   
}

function genDetails(movie) {
    if (movie.comments) {
        return `
        <p>${movie.Title}</p>
        <p>${movie.Year}</p>
        <ul>
            ${movie.comments.map(comment => comment ? ` 
                <li>${(new Date(comment.created)).toLocaleString()}: ${comment.text}</li>
            ` : '').join('')}
        </ul>
        <textarea></textarea>
        <br>
        <button type="button">Add comment</button>
    `
    }
    else {
        return `
            <p>${movie.Title}</p>
            <p>${movie.Year}</p>
            <textarea></textarea>
            <br>
            <button type="button">Add comment</button>
        `
    }
}

// Start
loadFavourites()
showFavourites()