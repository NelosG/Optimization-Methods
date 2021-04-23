package secondLab;

import java.util.Collections;

public abstract class AbstractSolver {
    protected double epsilon, alpha;
    protected long iterations, allIterations;
    protected QuadraticFunction quadraticFunction;

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
        Pair forRet = calcMin(x, xFunc, gradient, length);
        allIterations += iterations;
        return forRet;
    }

    public long getIterations() {
        return iterations;
    }

    public long getAllIterations() {
        return allIterations;
    }

    public long resetIterations() {
        long temp = allIterations;
        iterations = 0;
        allIterations = 0;
        return temp;
    }

    protected abstract Pair calcMin(Vector x, double xFunc, Vector gradient, double length);
}
