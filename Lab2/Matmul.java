import java.util.Random;

public class Matmul {

    public static double[][] randomMatrix(int m, int n) {
        double[][] out = new double[m][n];
        Random random = new Random();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                out[i][j] = random.nextDouble();
            }
        }
        
        return out;
    }

    public static double[][] matmul(double[][] A, double[][] B) {
        int rowsOut = A.length;
        int cols = A[0].length;
        int rows = B.length;
        int colsOut = B[0].length;

        if (cols != rows) {
            throw new IllegalArgumentException("MY ERROR: wrong matrix multiplication");
        }

        double[][] out = new double[rowsOut][colsOut];

        for (int i = 0; i < rowsOut; i++) {
            for (int j = 0; j < colsOut; j++) {
                for (int k = 0; k < B.length; k++) {
                    out[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return out;
    }

    public static void main(String[] args) {
        double timeSum = 0;

        for (int i = 0; i < 10; i++) {
            long startTime = System.nanoTime();
            double[][] randa = randomMatrix(600, 100);
            double[][] randb = randomMatrix(100, 600);
            double[][] mult = matmul(randa, randb);
            long endTime = System.nanoTime();
            timeSum += (endTime - startTime) / 1e9; // Convert nanoseconds to seconds
        }

        double averageTimePython = timeSum / 10;
        System.out.println(averageTimePython);
    }
}
