package secondLab;

public class ConjugateGradient extends AbstractSolver {

    public ConjugateGradient(QuadraticFunction quadraticFunction, double epsilon) {
        super(quadraticFunction, epsilon);
    }

    @Override
    protected Pair calcMin(Vector x, double xFunc, Vector gradient, double length) {
        Vector vectorP = gradient.multiplyByScalar(-1);
        while (length >= epsilon) {
            ++iterations;
            Vector ap = quadraticFunction.getA().multiplyByVector(vectorP);
            alpha = length / ap.scalarMultiplication(vectorP);
            Vector nextX = x.sum(vectorP.multiplyByScalar(alpha));
            Vector nextGradient = gradient.sum(ap.multiplyByScalar(alpha));
            double nextGradientLength = nextGradient.scalarMultiplication(nextGradient);
            double beta;
            if (iterations % x.size() == 0) {
                beta = 0;
            } else {
                beta = nextGradientLength / length;
            }
            vectorP = nextGradient.multiplyByScalar(-1).sum(vectorP.multiplyByScalar(beta));
            gradient = nextGradient;
            length = nextGradientLength;
            x = nextX;
        }
        return new Pair(x, quadraticFunction.apply(x));
    }
}
