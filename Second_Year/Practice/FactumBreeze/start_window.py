from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtWidgets import QFileDialog
from json_sensor_selector import Ui_JsonSensorWindow


class Ui_MainWindow(object):
    def open_json_sensor_selector(self):
        self.window = QtWidgets.QWidget()
        self.ui = Ui_JsonSensorWindow()
        self.ui.setupUi(self.window)
        self.window.show()

    def json_select_from_pc(self):
        res = QFileDialog.getOpenFileName(None, 'Select .json file', '/', 'JSON File (*.json)')

        if (res[0]) != '':
            self.open_json_sensor_selector()
            MainWindow.close()

    def csv_select_from_pc(self):
        res = QFileDialog.getOpenFileName(None, 'Select .csv file', '/', 'CSV File (*.csv)')

        if (res[0]) == '':
            print("Nothing selected.")
        else:
            print(res)

    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setFixedSize(360, 330)

        MainWindow.setWindowTitle("FactumBreeze")
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
        self.json_select_btn.setText(_translate("MainWindow", ".JSON"))
        self.csv_select_btn.setText(_translate("MainWindow", ".CSV"))


if __name__ == "__main__":
    import sys

    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()

    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)

    MainWindow.show()
    sys.exit(app.exec())
