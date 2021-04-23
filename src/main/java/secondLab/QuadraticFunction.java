package secondLab;

import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class QuadraticFunction implements Function<RealVector, Double> {

    private final RealMatrix a;
    private final RealVector b;
    private final double c;
    private final int n;

    public QuadraticFunction(RealMatrix a, RealVector b, double c) {
        this.n = a.getRowDimension();
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public Double apply(RealVector vector) {
        return (vector.dotProduct(MatrixHelper.mul(a, vector))) / 2
                + vector.dotProduct(b)
                + c;
    }

    public RealVector gradient(RealVector vector) {
        return MatrixHelper.mul(a, vector).add(b);
    }

    public int getN() {
        return n;
    }

    public RealMatrix getA(){
        return a;
    }
}
