package secondLab;

import org.apache.commons.math3.linear.RealVector;

public class VectorHelper {

    public static double length(RealVector vector) {
        double length = 0;
        for (double c : vector.toArray()) {
            length += c*c;
        }
        length = Math.sqrt(length);
        return length;
    }
}
