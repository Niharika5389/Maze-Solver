// ===== CONFIG =====
const rows = 10;   // adjust if needed
const cols = 10;

// start & end (match your C maze)
let start = { x: 0, y: 0 };
let end = { x: 5, y: 5 };

// ===== GRID SETUP =====
const grid = document.getElementById("grid");

for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {

        const cell = document.createElement("div");
        cell.classList.add("cell");

        cell.dataset.row = i;
        cell.dataset.col = j;

        grid.appendChild(cell);
    }
}

console.log("Grid created");

// ===== MARK START & END =====
function markStartEnd() {

    let startCell = document.querySelector(`[data-row='${start.x}'][data-col='${start.y}']`);
    let endCell = document.querySelector(`[data-row='${end.x}'][data-col='${end.y}']`);

    if (startCell) {
        startCell.style.backgroundColor = "green";
    } else {
        console.log("Start cell not found");
    }

    if (endCell) {
        endCell.style.backgroundColor = "red";
    } else {
        console.log("End cell not found");
    }
}

// call after grid is ready
markStartEnd();

// ===== RESET FUNCTION =====
function resetGrid() {

    let cells = document.querySelectorAll(".cell");

    cells.forEach(cell => {
        cell.style.backgroundColor = "";
    });

    markStartEnd();
}

// ===== ANIMATION FUNCTION =====
async function runAnimation() {

    resetGrid();

    console.log("Animation started");

    try {
        let res = await fetch("output.txt");

        if (!res.ok) {
            console.log("Error loading file");
            return;
        }

        let text = await res.text();
        let steps = text.split("\n");

        for (let line of steps) {

            let parts = line.trim().split(" ");

            if (parts.length < 3) continue;

            let type = parts[0];
            let x = parseInt(parts[1]);
            let y = parseInt(parts[2]);

            let cell = document.querySelector(`[data-row='${x}'][data-col='${y}']`);

            if (!cell) continue;

            // don't overwrite start/end
            if (x === start.x && y === start.y) continue;
            if (x === end.x && y === end.y) continue;

            if (type === "V") {
                cell.style.backgroundColor = "blue";
            }

            if (type === "P") {
                cell.style.backgroundColor = "yellow";
            }

            await new Promise(r => setTimeout(r, 40));
        }

    } catch (err) {
        console.log("Fetch failed:", err);
    }
}