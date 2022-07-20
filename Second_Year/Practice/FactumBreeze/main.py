from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtWidgets import QFileDialog


class Ui_MainWindow(object):
    def open_graph_viewer(self):
        self.window = QtWidgets.QMainWindow()
        self.ui = Ui_GraphViewWindow()
        self.ui.setupUi(self.window)
        self.window.show()

    def json_select_from_pc(self):
        import json
        res = QFileDialog.getOpenFileName(None, 'Select .json file', '/', 'JSON File (*.json)')

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

        self.main_graph = QtWidgets.QWidget(self.centralwidget)
        self.main_graph.setGeometry(QtCore.QRect(10, 160, 961, 401))
        self.main_graph.setObjectName("main_graph")

        self.verticalLayoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(10, 10, 261, 136))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")

        self.time_choose_layout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.time_choose_layout.setContentsMargins(0, 0, 0, 0)
        self.time_choose_layout.setObjectName("time_choose_layout")

        self.selected_time_begin = QtWidgets.QLabel(self.verticalLayoutWidget)
        font = QtGui.QFont()
        font.setPointSize(18)
        self.selected_time_begin.setFont(font)
        self.selected_time_begin.setStyleSheet("text-align: center;")
        self.selected_time_begin.setTextFormat(QtCore.Qt.TextFormat.AutoText)
        self.selected_time_begin.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        self.selected_time_begin.setObjectName("selected_time_begin")
        self.time_choose_layout.addWidget(self.selected_time_begin)

        self.selected_time_end = QtWidgets.QLabel(self.verticalLayoutWidget)
        font = QtGui.QFont()
        font.setPointSize(18)
        self.selected_time_end.setFont(font)
        self.selected_time_end.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        self.selected_time_end.setObjectName("selected_time_end")
        self.time_choose_layout.addWidget(self.selected_time_end)

        self.select_time_from_calendar_btn = QtWidgets.QPushButton(self.verticalLayoutWidget)
        font = QtGui.QFont()
        font.setPointSize(28)
        font.setItalic(False)
        self.select_time_from_calendar_btn.setFont(font)
        self.select_time_from_calendar_btn.setObjectName("select_time_from_calendar_btn")
        self.time_choose_layout.addWidget(self.select_time_from_calendar_btn)

        self.build_graph_btn = QtWidgets.QPushButton(self.centralwidget)
        self.build_graph_btn.setGeometry(QtCore.QRect(10, 570, 961, 24))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.build_graph_btn.setFont(font)
        self.build_graph_btn.setObjectName("build_graph_btn")

        self.verticalLayoutWidget_3 = QtWidgets.QWidget(self.centralwidget)
        self.verticalLayoutWidget_3.setGeometry(QtCore.QRect(280, 10, 193, 79))
        self.verticalLayoutWidget_3.setObjectName("verticalLayoutWidget_3")

        self.sns_and_type_select = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_3)
        self.sns_and_type_select.setContentsMargins(0, 0, 0, 0)
        self.sns_and_type_select.setObjectName("sns_and_type_select")

        self.sns_choose_btn = QtWidgets.QComboBox(self.verticalLayoutWidget_3)
        font = QtGui.QFont()
        font.setPointSize(17)
        self.sns_choose_btn.setFont(font)
        self.sns_choose_btn.setObjectName("sns_choose_btn")
        self.sns_choose_btn.addItem("")
        self.sns_choose_btn.addItem("")
        self.sns_and_type_select.addWidget(self.sns_choose_btn)

        self.data_choose_brn = QtWidgets.QComboBox(self.verticalLayoutWidget_3)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.data_choose_brn.setFont(font)
        self.data_choose_brn.setStyleSheet("text-align: center;")
        self.data_choose_brn.setObjectName("data_choose_brn")
        self.data_choose_brn.addItem("")
        self.data_choose_brn.addItem("")
        self.data_choose_brn.addItem("")
        self.data_choose_brn.addItem("")
        self.data_choose_brn.addItem("")
        self.sns_and_type_select.addWidget(self.data_choose_brn)

        self.json_file_path = QtWidgets.QLabel(self.centralwidget)
        self.json_file_path.setGeometry(QtCore.QRect(488, 10, 481, 31))
        font = QtGui.QFont()
        font.setFamily("Calibri")
        font.setPointSize(18)
        self.json_file_path.setFont(font)
        self.json_file_path.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        self.json_file_path.setObjectName("json_file_path")

        GraphViewWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(GraphViewWindow)
        QtCore.QMetaObject.connectSlotsByName(GraphViewWindow)

    def retranslateUi(self, GraphViewWindow):
        _translate = QtCore.QCoreApplication.translate
        GraphViewWindow.setWindowTitle(_translate("GraphViewWindow", "FactumBreeze: Graph viewer"))

        self.selected_time_begin.setText(_translate("GraphViewWindow", "NaN"))
        self.selected_time_end.setText(_translate("GraphViewWindow", "NaN"))

        self.select_time_from_calendar_btn.setText(_translate("GraphViewWindow", "Choose time"))

        self.build_graph_btn.setText(_translate("GraphViewWindow", "Build"))

        self.sns_choose_btn.setItemText(0, _translate("GraphViewWindow", "POCA K-2"))
        self.sns_choose_btn.setItemText(1, _translate("GraphViewWindow", "Тест Студии"))

        self.data_choose_brn.setItemText(0, _translate("GraphViewWindow", "light_lux"))
        self.data_choose_brn.setItemText(1, _translate("GraphViewWindow", "color_tempCT"))
        self.data_choose_brn.setItemText(2, _translate("GraphViewWindow", "weather_temp"))
        self.data_choose_brn.setItemText(3, _translate("GraphViewWindow", "weather_pressure"))
        self.data_choose_brn.setItemText(4, _translate("GraphViewWindow", "weather_humidity"))
        self.json_file_path.setText(_translate("GraphViewWindow", json_path))


if __name__ == "__main__":
    import sys

    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()

    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)

    MainWindow.show()
    sys.exit(app.exec())
