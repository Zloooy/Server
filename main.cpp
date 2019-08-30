#include <QApplication>
#include <QPushButton>
#include <unistd.h>
#include "child_classes/server.h"
#include "child_classes/graph_data_processor.h"
#include "child_classes/main_window.h"
#include "child_classes/graph.h"
#include "child_classes/chart_data_processor.h"
#include "child_classes/chart.h"
#include "child_classes/test_server.h"
int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    TestServer serv;
    std::cout << "Created server" << std::endl;
    GraphDataProcessor graph_dp;
    ChartDataProcessor chart_dp;
    std::cout << "Created data processor" << std::endl;
    //UI
    MainWindow main_window;
    std::cout << "Created main window" << std::endl;
    QPushButton cancel_button("Сброс");
    QObject::connect(&cancel_button, &QPushButton::clicked, [&serv]{serv.clear_listeners();});
    Graph graph;
    Chart chart;
    chart.start();
    std::cout << "Created plots" << std::endl;
    main_window.addWidgetAtRight(&cancel_button);
    main_window.addTab(&graph, "График");
    main_window.addTab(&chart, "Гистограмма");
    serv.addListenerChain(&graph_dp, &graph);
    serv.addListenerChain(&chart_dp, &chart);
    serv.start();
    std::cout << "Starting server" << std::endl;
    graph_dp.start();
    chart_dp.start();
    std::cout << "Starting data processor" << std::endl;
    //sleep(15);
    std::cout << "Stopping graph dg" <<std::endl;
    //graph_dp.stop();
    std::cout << "Stopping server" << std::endl;
    //serv.stop();
    main_window.show();
    return app.exec();
};
