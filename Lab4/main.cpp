#include <BroadenFletcherChen.h>
#include <Newton.h>
#include <NewtonDirectionDescent.h>
#include <NewtonOneDimension.h>
#include <Powell.h>
#include <Source.h>
#include <logger.h>

void run(const Source &source, logger &lg, int method_mode, bool start) {
    method *meth;
    switch (method_mode) {
        case (1): {
            meth = new NewtonDirectionDescent( );
            lg << "NewtonDirectionDescent" << '\n';
            break;
        }
        case (2): {
            meth = new NewtonOneDimension( );
            lg << "NewtonOneDimension" << '\n';
            break;
        }
        case (3): {
            meth = new BroadenFletcherChen( );
            lg << "BroadenFletcherChen" << '\n';
            break;
        }
        case (4): {
            meth = new Powell( );
            lg << "Powell" << '\n';
            break;
        }
        default: {
            meth = new Newton( );
            lg << "Newton" << '\n';
            break;
        }
    }
    if(start){
        lg << "Start: " << source.get_point( ).to_string( ) << '\n';
    }
    point res = meth->minimum(source.get_function( ), source.get_point( ), 0.000001);
    lg << "\nAnswer: " << res.to_string( ) << '\n';
    lg << "Iterations: " << meth->count_of_iterations( ) << '\n'
       << "----------------------------------" << '\n'
       << '\n';
    delete meth;
}

void run_1_1(Source& source) {
    logger lg("../../log_1_1.xlsx");
    for(int i = 5;i < source.get_mods_count(); ++i) {
        source.set_mod(i);
        lg.set_page("Func_" + std::to_string(i - 4));
        for(auto j : {0, 1, 2}) {
            run(source, lg,j, true);
        }
    }
    lg.close();
}

void run_1_2(Source &source) {
    logger lg("../../log_1_2.xlsx");
    for(int i = 0; i < 2; ++i) {
        source.set_mod(i);
        lg.set_page("Func_" + std::to_string(i + 1));
        for(auto j : {0, 1, 2}) {
            run(source, lg,j, true);
        }
    }
    lg.close();
}

void run_2(Source &source) {
    logger lg("../../log_2.xlsx");
    for(int i = 1; i < 5; ++i) {
        source.set_mod(i);
        lg.set_page("Func_" + std::to_string(i));
        for(auto j : {3, 4}) {
            run(source, lg,j, false);
        }
    }
    lg.close();
}

int main() {

    Source source;
    run_1_1(source);
    run_1_2(source);
    run_2(source);
}
