package secondLab;

import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

public class QuadraticFunction extends QuadrFunction {
    protected RealMatrix a;

    public QuadraticFunction(RealMatrix a, RealVector b, double c) {
        super();
        this.n = b.getDimension();
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public RealVector mulAtoVec(RealVector vector) {
        return MatrixHelper.mul(a, (vector));
    }

    @Override
    public Double apply(RealVector vector) {
        return (vector.dotProduct(MatrixHelper.mul(a, vector))) / 2
                + vector.dotProduct(b)
                + c;
    }

    @Override
    public RealVector gradient(RealVector vector) {
        return MatrixHelper.mul(a, vector).add(b);
    }

    @Override
    public double rBound() {
        return MatrixHelper.getMaxEigenValue(a);
    }
}
