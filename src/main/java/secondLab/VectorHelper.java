package secondLab;

import org.apache.commons.math3.linear.RealVector;

public class VectorHelper {

    public static double length(RealVector vector) {
        return Math.sqrt(vector.dotProduct(vector));
    }
}
