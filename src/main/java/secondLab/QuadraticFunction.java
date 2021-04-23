package secondLab;

import java.util.function.Function;

public class QuadraticFunction implements Function<Vector, Double> {

    private final Matrix a;
    private final Vector b;
    private final double c;
    private final int n;

    public QuadraticFunction(Matrix a, Vector b, double c) {
        this.n = a.size();
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public Double apply(Vector vector) {
        return (vector.scalarMultiplication(a.multiplyByVector(vector))) / 2
                + vector.scalarMultiplication(b)
                + c;
    }

    public Vector gradient(Vector vector) {
        return a.multiplyByVector(vector).sum(b);
    }

    public int getN() {
        return n;
    }

    public Matrix getA(){
        return a;
    }
}
