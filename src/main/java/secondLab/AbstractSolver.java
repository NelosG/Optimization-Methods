package secondLab;

import java.util.Collections;

public abstract class AbstractSolver {
    double epsilon, alpha;
    long iterations;
    QuadraticFunction quadraticFunction;

    public AbstractSolver(QuadraticFunction quadraticFunction, double epsilon) {
        this.epsilon = epsilon;
        this.quadraticFunction = quadraticFunction;
        this.alpha = 100;
    }

    public Pair findMin() {
        Vector x = new Vector(Collections.nCopies(quadraticFunction.getN(), 0.0));
        double xFunc = quadraticFunction.apply(x);
        Vector gradient = quadraticFunction.gradient(x);
        double length = gradient.length();
        if (length < epsilon) {
            return new Pair(x, xFunc);
        }
        return calcMin(x, xFunc, gradient, length);
    }

    public long getIterations() {
        return iterations;
    }

    public long resetIterations() {
        long temp = iterations;
        iterations = 0;
        return temp;
    }

    protected abstract Pair calcMin(Vector x, double xFunc, Vector gradient, double length);
}
