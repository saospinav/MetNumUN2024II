function randomMatrix(m, n) {
    let out = [];
    for (let row = 0; row < m; row++) {
        let newRow = [];
        for (let col = 0; col < n; col++) {
            newRow.push(Math.random());
        }
        out.push(newRow);
    }
    return out;
}

function matmul(A, B) {
    // Multiply matrix A by matrix B.
    let rows_out = A.length;
    let cols = A[0].length;
    let rows = B.length;
    let cols_out = B[0].length;

    if (!(cols === rows)) {
        throw new Error("MY ERROR: wrong matrix multiplication");
    }

    let out = new Array(rows_out);
    for (let i = 0; i < rows_out; i++) {
        out[i] = new Array(cols_out).fill(0);
        for (let j = 0; j < cols_out; j++) {
            for (let k = 0; k < B.length; k++) {
                out[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return out;
}

function main() {
    let timeSum = 0;

    for (let i = 0; i < 10; i++) {
        let startTime = Date.now();
        let randa = randomMatrix(600, 100);
        let randb = randomMatrix(100, 600);
        let mult = matmul(randa, randb);
        let endTime = Date.now();
        timeSum += endTime - startTime;
    }

    let averageTimeJavaScript = timeSum / 10;
    console.log(averageTimeJavaScript);
    return averageTimeJavaScript;
}

main()