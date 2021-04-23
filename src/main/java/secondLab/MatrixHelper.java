package secondLab;
import org.apache.commons.math3.linear.*;

import java.util.Arrays;

public class MatrixHelper {

    public static double getMaxEigenValue(RealMatrix matrix) {
        return Arrays.stream(new EigenDecomposition (matrix).getRealEigenvalues()).max().getAsDouble();
    }

    public static RealVector mul(RealMatrix a, RealVector vector) {
        double[] res = new double[a.getRowDimension()];
        for(int i = 0 ; i< a.getRowDimension(); ++i) {
            res[i] = vector.dotProduct(a.getRowVector(i));
        }

        return new ArrayRealVector(res);
    }
}
