#include "Methods/BroadenFletcherChen.h"
#include "Methods/Newton.h"
#include "Methods/NewtonDirectionDescent.h"
#include "Methods/NewtonOneDimension.h"
#include "Methods/Powell.h"
#include "Source.h"
#include <iostream>
#include <logger.h>


void run(const Source &source, logger& lg) {
    for (int i = 1, method_mode; i < 5; i++) {
        method_mode = i;
        method *meth;
        switch (method_mode) {
            case (1): {
                meth = new NewtonDirectionDescent();
                lg << "NewtonDirectionDescent" << '\n';
                break;
            }
            case (2): {
                meth = new NewtonOneDimension();
                lg << "NewtonOneDimension" << '\n';
                break;
            }
            case (3): {
                meth = new BroadenFletcherChen();
                lg << "BroadenFletcherChen" << '\n';
                break;
            }
            case (4): {
                meth = new Powell();
                lg << "Powell" << '\n';
                break;
            }
            default: {
                meth = new Newton();
                lg << "Newton" << '\n';
                break;
            }
        }
        lg << "Start: " << source.get_point().to_string() << '\n';
        point res = meth->minimum(source.get_function(), source.get_point(), 0.000001);
        lg << "\nAnswer: " << res.to_string() << '\n';
        lg << "Iterations: " << meth->count_of_iterations() << '\n' << "----------------------------------" << '\n' << '\n';
        delete meth;
    }
}
int main() {

    Source source;
    logger lg("../../log.xlsx");
    for (int mode = 0; mode < source.get_mods_count(); ++mode) {
        source.change_mod(mode);
        lg.set_page("Mode" + std::to_string(mode+1));
        run(source, lg);
    }
}
