from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtWidgets import QFileDialog
from pyqtgraph.Qt import QtCore, QtGui
import pyqtgraph


class Ui_MainWindow(object):
    def open_graph_viewer(self):
        self.window = QtWidgets.QMainWindow()
        self.ui = Ui_GraphViewWindow()
        self.ui.setupUi(self.window)
        self.window.show()

    def json_select_from_pc(self):
        import json
        res = QFileDialog.getOpenFileName(None, 'Select .json file', './', 'JSON File (*.json)')

        if (res[0]) != '':
            global json_path
            json_path = res[0]

            global data
            with open(json_path, 'r') as json_file:
                data = json.load(json_file)

            json_path = f"SELECTED: [{json_path.split('/')[-1]}]"

            self.open_graph_viewer()
            MainWindow.close()

    def csv_select_from_pc(self):
        res = QFileDialog.getOpenFileName(None, 'Select .csv file', '/', 'CSV File (*.csv)')

        if (res[0]) == '':
            print("Nothing selected.")
        else:
            print('NEED TO FINALIZE')

    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setFixedSize(360, 330)

        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")

        self.verticalLayoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(60, 60, 241, 206))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")

        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")

        self.json_select_btn = QtWidgets.QPushButton(self.verticalLayoutWidget)

        font = QtGui.QFont()
        font.setFamily("Calibri")
        font.setPointSize(72)
        font.setBold(False)

        self.json_select_btn.setFont(font)
        self.json_select_btn.setStyleSheet("QPushButton {\n""    padding: -10px;\n""}")
        self.json_select_btn.setObjectName("json_select_btn")
        self.json_select_btn.clicked.connect(self.json_select_from_pc)
        self.verticalLayout.addWidget(self.json_select_btn)

        self.csv_select_btn = QtWidgets.QPushButton(self.verticalLayoutWidget)

        font = QtGui.QFont()
        font.setFamily("Calibri")
        font.setPointSize(72)

        self.csv_select_btn.setFont(font)
        self.csv_select_btn.setStyleSheet("QPushButton {\n""    padding: -10px;\n""}")
        self.csv_select_btn.setObjectName("csv_select_btn")
        self.csv_select_btn.clicked.connect(self.csv_select_from_pc)
        self.verticalLayout.addWidget(self.csv_select_btn)

        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "FactumBreeze: File selector"))

        self.json_select_btn.setText(_translate("MainWindow", ".JSON"))
        self.csv_select_btn.setText(_translate("MainWindow", ".CSV"))


class Ui_GraphViewWindow(object):
    def setupUi(self, GraphViewWindow):
        GraphViewWindow.setObjectName("GraphViewWindow")
        GraphViewWindow.setFixedSize(980, 600)

        self.centralwidget = QtWidgets.QWidget(GraphViewWindow)
        self.centralwidget.setObjectName("centralwidget")

        self.verticalLayoutWidget_2 = QtWidgets.QWidget(self.centralwidget)
        self.verticalLayoutWidget_2.setGeometry(QtCore.QRect(10, 100, 961, 491))
        self.verticalLayoutWidget_2.setObjectName("verticalLayoutWidget_2")
        self.build_graph_layout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_2)
        self.build_graph_layout.setContentsMargins(0, 0, 0, 0)
        self.build_graph_layout.setObjectName("build_graph_layout")

        # ------------------------------------------------------------------------------------------------------------
        self.main_graph = pyqtgraph.plot()

        global x, y, graph_pen, graph_x_label, graph_y_label, graph_bg_color, style_of_label_sides
        y = [5, 5, 7, 10, 3, 8, 9, 1, 6, 2]
        x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

        # --- This is bar graph parameters ---
        # self.main_graph_bar = pyqtgraph.BarGraphItem(x=x, height=y, width=0.2, brush='g')
        # self.main_graph.addItem(self.main_graph_bar)
        # --- This is bar graph parameters

        graph_y_label = 'NaN'
        graph_x_label = 'NaN'
        graph_bg_color = 'w'
        style_of_label_sides = {"color": "black", "font-size": "10px"}
        graph_pen = pyqtgraph.mkPen(color='k', width=5, style=QtCore.Qt.PenStyle.SolidLine)

        self.main_graph.setBackground(graph_bg_color)
        self.main_graph.setLabel('left', graph_y_label, **style_of_label_sides)
        self.main_graph.setLabel('bottom', graph_x_label, **style_of_label_sides)
        self.main_graph.showGrid(x=True, y=True)

        # --- This is graph time limiter ---
        # self.main_graph.setXRange(selected_time_begin, selected_time_end, padding=0)
        # --- This is graph time limiter ---

        self.main_graph.plot(x, y, pen=graph_pen)

        self.build_graph_layout.addWidget(self.main_graph)
        # ------------------------------------------------------------------------------------------------------------

        self.change_file_button = QtWidgets.QPushButton(self.verticalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.change_file_button.setFont(font)
        self.change_file_button.setObjectName("change_file_button")
        self.build_graph_layout.addWidget(self.change_file_button)

        self.horizontalLayoutWidget_2 = QtWidgets.QWidget(self.centralwidget)
        self.horizontalLayoutWidget_2.setGeometry(QtCore.QRect(10, 10, 961, 82))
        self.horizontalLayoutWidget_2.setObjectName("horizontalLayoutWidget_2")
        self.menu_bar_layout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget_2)
        self.menu_bar_layout.setContentsMargins(0, 0, 0, 0)
        self.menu_bar_layout.setObjectName("menu_bar_layout")

        self.time_choose_layout = QtWidgets.QVBoxLayout()
        self.time_choose_layout.setObjectName("time_choose_layout")

        self.time_limiter_begin = QtWidgets.QDateTimeEdit(self.horizontalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.time_limiter_begin.setFont(font)
        self.time_limiter_begin.setCalendarPopup(True)
        self.time_limiter_begin.setObjectName("time_limiter_begin")
        self.time_choose_layout.addWidget(self.time_limiter_begin)

        self.time_limiter_end = QtWidgets.QDateTimeEdit(self.horizontalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.time_limiter_end.setFont(font)
        self.time_limiter_end.setCalendarPopup(True)
        self.time_limiter_end.setObjectName("time_limiter_end")
        self.time_choose_layout.addWidget(self.time_limiter_end)
        self.menu_bar_layout.addLayout(self.time_choose_layout)

        self.sns_and_type_select = QtWidgets.QVBoxLayout()
        self.sns_and_type_select.setObjectName("sns_and_type_select")

        self.sns_choose_btn = QtWidgets.QComboBox(self.horizontalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.sns_choose_btn.setFont(font)
        self.sns_choose_btn.setObjectName("sns_choose_btn")
        self.sns_choose_btn.addItem("")
        self.sns_choose_btn.addItem("")
        self.sns_choose_btn.currentTextChanged.connect(self.crnt_dvc_changed)
        self.sns_and_type_select.addWidget(self.sns_choose_btn)

        self.data_choose_btn = QtWidgets.QComboBox(self.horizontalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.data_choose_btn.setFont(font)
        self.data_choose_btn.setStyleSheet("text-align: center;")
        self.data_choose_btn.setObjectName("data_choose_btn")
        self.data_choose_btn.addItem("")
        self.data_choose_btn.addItem("")
        self.data_choose_btn.addItem("")
        self.data_choose_btn.addItem("")
        self.data_choose_btn.addItem("")
        self.sns_and_type_select.addWidget(self.data_choose_btn)
        self.menu_bar_layout.addLayout(self.sns_and_type_select)

        self.average_and_clear_graph_select = QtWidgets.QVBoxLayout()
        self.average_and_clear_graph_select.setObjectName("average_and_clear_graph_select")

        self.average_graph_btn = QtWidgets.QComboBox(self.horizontalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.average_graph_btn.setFont(font)
        self.average_graph_btn.setObjectName("average_graph_btn")
        self.average_graph_btn.addItem("")
        self.average_graph_btn.addItem("")
        self.average_graph_btn.addItem("")
        self.average_graph_btn.addItem("")
        self.average_graph_btn.addItem("")
        self.average_and_clear_graph_select.addWidget(self.average_graph_btn)

        self.graph_type_and_clear_layout = QtWidgets.QHBoxLayout()
        self.graph_type_and_clear_layout.setObjectName("graph_type_and_clear_layout")

        self.graph_type_btn = QtWidgets.QComboBox(self.horizontalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.graph_type_btn.setFont(font)
        self.graph_type_btn.setObjectName("graph_type_btn")
        self.graph_type_btn.addItem("")
        self.graph_type_btn.addItem("")
        self.graph_type_btn.currentTextChanged.connect(self.crnt_graph_type_changed)
        self.graph_type_and_clear_layout.addWidget(self.graph_type_btn)

        self.clear_graph_btn = QtWidgets.QPushButton(self.horizontalLayoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.clear_graph_btn.setFont(font)
        self.clear_graph_btn.setObjectName("clear_graph_btn")
        self.clear_graph_btn.clicked.connect(self.main_graph.clear)
        self.graph_type_and_clear_layout.addWidget(self.clear_graph_btn)

        self.average_and_clear_graph_select.addLayout(self.graph_type_and_clear_layout)
        self.menu_bar_layout.addLayout(self.average_and_clear_graph_select)

        GraphViewWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(GraphViewWindow)
        QtCore.QMetaObject.connectSlotsByName(GraphViewWindow)

    def crnt_dvc_changed(self):
        current_sns = self.sns_choose_btn.currentText()
        POCA_sns = ['light_lux', 'color_tempCT', 'weather_temp', 'weather_pressure', 'weather_humidity']
        STD_sns = ['TCS34725_lux', 'BMP280_temp', 'BME280_temp', 'DS18B20_temp', 'AM2321_temp',
                   'TCS34725_colorTemp',
                   'TCS34725_colorTempCT', 'BMP280_pressure', 'BME280_pressure', 'BME280_humidity',
                   'AM2321_humidity']

        if current_sns == 'Тест Студии':
            self.data_choose_btn.clear()
            self.data_choose_btn.addItems(STD_sns)
        else:
            self.data_choose_btn.clear()
            self.data_choose_btn.addItems(POCA_sns)

    def crnt_graph_type_changed(self):
        self.main_graph.clear()

        current_type_by_index = self.graph_type_btn.currentIndex()
        if current_type_by_index == 0:
            self.main_graph.setBackground(graph_bg_color)
            self.main_graph.setLabel('left', graph_y_label, **style_of_label_sides)
            self.main_graph.setLabel('bottom', graph_x_label, **style_of_label_sides)
            self.main_graph.showGrid(x=True, y=True)
            self.main_graph.plot(x, y, pen=graph_pen)
        elif current_type_by_index == 1:
            self.main_graph_bar = pyqtgraph.BarGraphItem(x=x, height=y, width=0.2, brush='k')
            self.main_graph.addItem(self.main_graph_bar)

    def retranslateUi(self, GraphViewWindow):
        _translate = QtCore.QCoreApplication.translate
        GraphViewWindow.setWindowTitle(_translate("GraphViewWindow", "FactumBreeze: Graph viewer"))

        self.build_graph_btn.setText(_translate("GraphViewWindow", "Сменить JSON файл"))

        self.time_limiter_begin.setDisplayFormat(_translate("GraphViewWindow", "dd.MM.yyyy H:mm:ss"))
        self.time_limiter_end.setDisplayFormat(_translate("GraphViewWindow", "dd.MM.yyyy H:mm:ss"))

        self.sns_choose_btn.setItemText(0, _translate("GraphViewWindow", "POCA K-2"))
        self.sns_choose_btn.setItemText(1, _translate("GraphViewWindow", "Тест Студии"))

        self.data_choose_btn.setItemText(0, _translate("GraphViewWindow", "light_lux"))
        self.data_choose_btn.setItemText(1, _translate("GraphViewWindow", "color_tempCT"))
        self.data_choose_btn.setItemText(2, _translate("GraphViewWindow", "weather_temp"))
        self.data_choose_btn.setItemText(3, _translate("GraphViewWindow", "weather_pressure"))
        self.data_choose_btn.setItemText(4, _translate("GraphViewWindow", "weather_humidity"))

        self.average_graph_btn.setItemText(0, _translate("GraphViewWindow", "Без осреднений"))
        self.average_graph_btn.setItemText(1, _translate("GraphViewWindow", "Осреднённые за час"))
        self.average_graph_btn.setItemText(2, _translate("GraphViewWindow", "Осреднённые за 3 часа"))
        self.average_graph_btn.setItemText(3, _translate("GraphViewWindow", "Осреднённые за сутки"))
        self.average_graph_btn.setItemText(4, _translate("GraphViewWindow", "Минимум и максимум за сутки"))

        self.graph_type_btn.setItemText(0, _translate("GraphViewWindow", "Линейный график"))
        self.graph_type_btn.setItemText(1, _translate("GraphViewWindow", "Столбчатый график"))

        self.clear_graph_btn.setText(_translate("GraphViewWindow", "Очистить"))


if __name__ == "__main__":
    import sys

    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()

    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)

    MainWindow.show()
    sys.exit(app.exec())
