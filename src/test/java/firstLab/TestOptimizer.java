package firstLab;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.LinkedList;
import java.util.List;
import java.util.function.Function;

public class TestOptimizer {

    private static Optimizer optimizer;
    private static final double EPS = .01;
    private static final List<Pair<Function<Double, Double>, Pair<Pair<Double, Double>, Double>>> functions = new LinkedList<>();
    private static int index = 0;

    static {
        functions.add(new Pair<>(x -> Math.pow(x, 2.0) + Math.exp(-0.35 * x), new Pair<>(new Pair<>(-2., 3.), 0.16517))); // [-2,3] x = 0.16517
        functions.add(new Pair<>(x -> Math.pow(x, 4.0) - 1.5 * Math.atan(x), new Pair<>(new Pair<>(-1., 1.), 0.642636))); // [-1,1] x = 0.642636
        functions.add(new Pair<>(x -> x * Math.sin(x) + 2 * Math.cos(x), new Pair<>(new Pair<>(-6., -4.), 4.49341))); // [-6,-4] x = +-4.49341
        functions.add(new Pair<>(x -> x - Math.log(x), new Pair<>(new Pair<>(.5, 4.), 0.999991))); // [0.5,4] x = 0.999991
        functions.add(new Pair<>(x -> 10 * x * Math.log(x) + Math.pow(x, 2.0) / 2, new Pair<>(new Pair<>(.1, 2.5), 0.382212))); // [0.1,2.5] x = 0.382212
        functions.add(new Pair<>(x -> -5 * Math.pow(x, 5.0) + 4 * Math.pow(x, 4.0) - 12 * Math.pow(x, 3.0) + 11 * Math.pow(x, 2.0) - 2 * x + 1, new Pair<>(new Pair<>(.1, 2.5), 0.897633))); // [0.1,2.5] x = 0.897633
        functions.add(new Pair<>(x -> Math.pow(Math.log10(x - 2), 2.0) + Math.pow(Math.log10(10 - x), 2.0) - Math.pow(x, 0.2), new Pair<>(new Pair<>(6., 9.9), 8.72691))); // [6, 9.9] x = 8.72691
        functions.add(new Pair<>(x -> -3 * x * Math.sin(0.75 * x) + Math.exp(-2 * x), new Pair<>(new Pair<>(0., 2 * Math.PI), 2.70648))); // [0,2*pi] x = 2.70648
        functions.add(new Pair<>(x -> Math.exp(3 * x) + 5 * Math.exp(-2 * x), new Pair<>(new Pair<>(0., 1.), 1. / 5. * Math.log(10. / 3.)))); // [0,1] x = 1/5 * ln(10/3)
        functions.add(new Pair<>(x -> 0.2 * x * Math.log(x) + Math.pow(x - 2.3, 2.0), new Pair<>(new Pair<>(.5, 2.5), 2.2219))); // [0.5,2.5] x = 2.2219
    }

    @Before
    public void initOptimizer() {
        index = 0;
        optimizer = new DichotomyOptimizer();
    }

    @After
    public void cleanOptimizer() {
        optimizer = null;
    }

    @Test
    public void testOptimizersResult() {
        functions.forEach(p -> {
            double result = optimizer.optimize(p.s.f.f, p.s.f.s, EPS, p.f);
            Assert.assertTrue("test " + index + " failed, expected: " + p.s.s + ", got: " + result, Math.abs(result - p.s.s) < EPS);
            index++;
        });
    }

    private static class Pair<F, S> {

        final F f;
        final S s;

        public Pair(F f, S s) {
            this.f = f;
            this.s = s;
        }
    }
}
