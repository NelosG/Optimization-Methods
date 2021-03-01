package firstLab;

import org.javatuples.Quintet;
import org.junit.After;
import org.junit.Assert;
import org.junit.Test;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Function;

public abstract class BaseTest {
    protected static List<Quintet<Double, Double, Function<Double, Double>, Double, Double>> functions = new LinkedList<>();
    protected double EPS = 10e-9;
    protected Optimizer optimizer;
    protected Logger logger;
    static {
        /*1*/
        functions.add(new Quintet<>(-2., 3., x -> Math.pow(x, 2.0) + Math.exp(-0.35 * x), 0.16517, 0.97111)); // [-2,3] x = 0.16517; y = 0.97111

        /*2*/
        functions.add(new Quintet<>(-1., 1., x -> Math.pow(x, 4.0) - 1.5 * Math.atan(x), 0.642636, -0.686218)); // [-1,1] x = 0.642636; y = -0.686218

        /*3*/
        functions.add(new Quintet<>(-6., -4., x -> x * Math.sin(x) + 2 * Math.cos(x), 4.49341, -4.82057)); // [-6,-4] x = +-4.49341; y = -4.82057

        /*4*/
        functions.add(new Quintet<>(0.5, 4., x -> x - Math.log(x), 1., 1.)); // [0.5,4] x = 1. | 0.999991; y = 1.

        /*5*/
        functions.add(new Quintet<>(0.1, 2.5, x -> 10 * x * Math.log(x) + Math.pow(x, 2.0) / 2, 0.382212, -3.74908)); // [0.1,2.5] x = 0.382212; y = -3.74908

        /*6*/
        functions.add(new Quintet<>(-0.5, 0.5, x -> -5 * Math.pow(x, 5.0) + 4 * Math.pow(x, 4.0) - 12 * Math.pow(x, 3.0) + 11 * Math.pow(x, 2.0) - 2 * x + 1, 0.10986, 0.897633)); // [0.1,2.5] x = 0.10986; y = 0.897633

        /*7*/
        functions.add(new Quintet<>(6., 9.9, x -> Math.pow(Math.log10(x - 2), 2.0) + Math.pow(Math.log10(10 - x), 2.0) - Math.pow(x, 0.2), 8.72691, -0.846037)); // [6, 9.9] x = 8.72691; y = -0.846037

        /*8*/
        functions.add(new Quintet<>(0., 2 * Math.PI, x -> -3 * x * Math.sin(0.75 * x) + Math.exp(-2 * x), 2.70648, -7.27436)); // [0,2*pi] x = 2.70648; y = -7.27436

        /*9*/
        functions.add(new Quintet<>(0., 1., x -> Math.exp(3 * x) + 5 * Math.exp(-2 * x), 0.24079, 5.1483)); // [0,1] x = 0.24079; y = 5.1483

        /*10*/
        functions.add(new Quintet<>(0.5, 2.5, x -> 0.2 * x * Math.log10(x) + Math.pow(x - 2.3, 2.0), 2.2219, 0.160177)); // [0.5,2.5] x = 2.2219; y = 0.160177
    }


    void run(int ind) {
        logger.writeln("Test: " + ind);
        ind--;
        Quintet<Double, Double, Function<Double, Double>, Double, Double> q = functions.get(ind);
        double expected = q.getValue3();
        double xactual = optimizer.optimize(q.getValue0(), q.getValue1(), EPS, q.getValue2());
        xactual -= xactual % EPS;
        double yactual = q.getValue2().apply(xactual);
        yactual -= yactual % EPS;
        Assert.assertTrue("Expression: " + (ind + 1) + " Expected: x = " + expected +
                        " y = " + q.getValue4() + "\n                         " +
                        " but Actual: x = " + xactual + " y = " + yactual + "\n"
                ,   Math.abs(yactual) - Math.abs(q.getValue4()) < EPS);
    }

    @Test
    public void TestExpression1() {
        run(1);
    }

    @Test
    public void TestExpression2() {
        run(2);
    }

    @Test
    public void TestExpression3() {
        run(3);
    }

    @Test
    public void TestExpression4() {
        run(4);
    }

    @Test
    public void TestExpression5() {
        run(5);
    }

    @Test
    public void TestExpression6() {
        run(6);
    }

    @Test
    public void TestExpression7() {
        run(7);
    }

    @Test
    public void TestExpression8() {
        run(8);
    }

    @Test
    public void TestExpression9() {
        run(9);
    }

    @Test
    public void TestExpression10() {
        run(10);
    }

    @After
    public void cleanOptimizer() {
        try {
            logger.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
        optimizer = null;
    }
}
