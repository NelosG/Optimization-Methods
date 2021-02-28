package firstLab;

import org.javatuples.Quartet;
import org.junit.Assert;
import org.junit.Test;

import java.util.LinkedList;
import java.util.List;
import java.util.function.Function;

public class TestOptimizer {

    private static final double EPS = .00000001;
    private static final List<Quartet<Double, Double,Function<Double, Double>, Double>> functions = new LinkedList<>();

    @Test
    public void DichotomyOptimizerTest() {
        Assert.assertTrue("DichotomyOptimizerTest failed",
                startTest(new DichotomyOptimizer(), "DichotomyOptimizer Err"));
    }





    static {
        /*1*/functions.add(new Quartet<>(-2., 3., x -> Math.pow(x, 2.0) + Math.exp(-0.35 * x), 0.16517)); // [-2,3] x = 0.16517

        /*2*/functions.add(new Quartet<>(-1., 1., x -> Math.pow(x, 4.0) - 1.5 * Math.atan(x), 0.642636)); // [-1,1] x = 0.642636

        /*3*/functions.add(new Quartet<>(-6., -4., x -> x * Math.sin(x) + 2 * Math.cos(x), 4.49341)); // [-6,-4] x = +-4.49341

        /*4*/functions.add(new Quartet<>(.5, 4., x -> x - Math.log(x), 0.999991)); // [0.5,4] x = 0.999991

        /*5*/functions.add(new Quartet<>(.1, 2.5, x -> 10 * x * Math.log(x) + Math.pow(x, 2.0) / 2, 0.382212)); // [0.1,2.5] x = 0.382212

        /*6*/functions.add(new Quartet<>(.1, 2.5, x -> -5 * Math.pow(x, 5.0) + 4 * Math.pow(x, 4.0) - 12 * Math.pow(x, 3.0) + 11 * Math.pow(x, 2.0) - 2 * x + 1, 0.897633)); // [0.1,2.5] x = 0.897633

        /*7*/functions.add(new Quartet<>(6., 9.9,x -> Math.pow(Math.log10(x - 2), 2.0) + Math.pow(Math.log10(10 - x), 2.0) - Math.pow(x, 0.2), 8.72691)); // [6, 9.9] x = 8.72691

        /*8*/functions.add(new Quartet<>(0., 2 * Math.PI, x -> -3 * x * Math.sin(0.75 * x) + Math.exp(-2 * x), 2.70648)); // [0,2*pi] x = 2.70648

        /*9*/functions.add(new Quartet<>(0., 1., x -> Math.exp(3 * x) + 5 * Math.exp(-2 * x), 1. / 5. * Math.log(10. / 3.))); // [0,1] x = 1/5 * ln(10/3)

        /*10*/functions.add(new Quartet<>(.5, 2.5, x -> 0.2 * x * Math.log(x) + Math.pow(x - 2.3, 2.0), 2.2219)); // [0.5,2.5] x = 2.2219
    }


    void run(int ind, Optimizer optimizer) {
        Quartet<Double, Double,Function<Double, Double>, Double> q = functions.get(ind);
        double expected = q.getValue3();
        double actual = optimizer.optimize(q.getValue0(), q.getValue1(), EPS, q.getValue2());
        Assert.assertTrue("Expression: " + (ind + 1) + " Expected: " + expected + " but Actual: " + actual + "\n"
                ,Math.abs(actual) - Math.abs(expected) < EPS);
    }

    boolean startTest(Optimizer optimizer, String errMess) {
        boolean flag = true;
        for (int i = 0; i < 10; i++) {
            try {
                run(i, optimizer);
            } catch (AssertionError e) {
                System.err.println(errMess + ": " + e.getMessage());
                flag = false;
            }
        }
        return flag;
    }
}
