/**
 * Rendering the states of the game
 *      - output: HTML elements
 *      - from the bottom to the top
 */

import { Field, FieldState } from "./field.js";
import { Stage } from "./state.js";

// UI rendering -> main funtcion call just the render() + render calls the other renders
export function render(state) {
    // return renderTalbe(state.board);
    return `
    ${renderStage(state.stage)}
    ${renderTalbe(state.board)}
    `
}

function renderStage(stage) {
    return `
    <span>
    ${
        stage === Stage.VICTORY 
        ? `😎` 
        : (stage === Stage.GAME_OVER 
            ? `😢` 
            : `😃`)
    }
    </span>
    `
}

// Rendering the table
export function renderTalbe(board) {
    return `<table>${board.map(renderRow).join("")}</table>`;
    
}

// Rendering the rows of the table
export function renderRow (row) {
    // a row contains an array of fields
    // generate HTML code -> map and join are very important (while rendering)
    return `<tr>${row.map(renderField).join("")}</tr>`;    
}

// Rendering a field
export function renderField (field) {
    // if revealed -> mine or contains the number of the neighbours
    if (field.state === FieldState.REVEALED) {
        return `
            <td>
            ${
                field.isMine 
                    ? (field.isBlownUp ? `❌` : `💣` ) 
                    : ((field.neighborCount > 0) ? field.neighborCount : ``)
            }
            </td>
        `;
    }
    // if unrevield -> flagged or nothing
    else {
        return `
            <td>
                <button>${field.state === FieldState.FLAGGED ? `⛳` : ``}</button>
            </td>
        `
    }
}