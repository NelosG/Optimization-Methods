package firstLab;

import org.junit.Before;

public class FibonacciTest extends BaseTest {

    @Before
    public void initOptimizer() {
        optimizer = new Fibonacci();
    }

}
