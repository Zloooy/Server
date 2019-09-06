#include <QApplication>
#include <QPushButton>
#include <unistd.h>
#include "child_classes/server.h"
#include "child_classes/graph_data_processor.h"
#include "child_classes/main_window.h"
#include "child_classes/graph.h"
#include "child_classes/chart_data_processor.h"
#include "child_classes/chart.h"
//#include "child_classes/test_server.h"
#include "child_classes/stats_tab.h"
#include "child_classes/stats_label.h"
#include "child_classes/min_max_data_processor.h"
#include "child_classes/average_data_processor.h"
#include "child_classes/square_deviation_data_processor.h"
#include "child_classes/expected_value_data_processor.h"
int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    //TestServer serv;
    Server serv;
    std::cout << "Created server" << std::endl;
    GraphDataProcessor graph_dp;
    ChartDataProcessor chart_dp;
    MinMaxDataProcessor min_max_dp;
    AverageDataProcessor average_dp;
    SquareDeviationDataProcessor sqdev_dp;
    ExpectedValueDataProcessor expected_value_dp;
    std::cout << "Created data processor" << std::endl;
    //UI
    MainWindow main_window;
    std::cout << "Created main window" << std::endl;
    QPushButton cancel_button("Сброс");
    QObject::connect(&cancel_button, &QPushButton::clicked, [&serv]{serv.clear_listeners();});
    Graph graph;
    Chart chart;
    StatsTab stats_tab;
    StatsLabel min_max("Мнинмум: нет данных\nМаксимум: нет данных"), average("Среднее:\tнет данных"), sqdev("СКО:\tнет данных"), expected_value("Математическое ожидание:\tнет данных");
    stats_tab.addStats(&min_max);
    stats_tab.addStats(&average);
    stats_tab.addStats(&sqdev);
    stats_tab.addStats(&expected_value);
    chart.start();
    min_max.start();
    average.start();
    sqdev.start();
    expected_value.start();
    std::cout << "Created plots" << std::endl;
    main_window.addWidgetAtRight(&cancel_button);
    main_window.addTab(&graph, "График");
    main_window.addTab(&chart, "Гистограмма");
    main_window.addTab(&stats_tab, "Статистика");
    serv.addListenerChain(&graph_dp, &graph);
    serv.addListenerChain(&chart_dp, &chart);
    serv.addListenerChain(&min_max_dp, &min_max);
    serv.addListenerChain(&average_dp, &average);
    serv.addListenerChain(&sqdev_dp, &sqdev);
    serv.addListenerChain(&expected_value_dp, &expected_value);
    serv.start();
    std::cout << "Starting server" << std::endl;
    graph_dp.start();
    chart_dp.start();
    min_max_dp.start();
    average_dp.start();
    sqdev_dp.start();
    expected_value_dp.start();
    std::cout << "Starting data processor" << std::endl;
    //sleep(15);
    std::cout << "Stopping graph dg" <<std::endl;
    //graph_dp.stop();
    std::cout << "Stopping server" << std::endl;
    //serv.stop();
    main_window.show();
    return app.exec();
};
