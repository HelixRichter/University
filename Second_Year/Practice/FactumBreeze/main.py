from PyQt6 import QtWidgets
from PyQt6.QtWidgets import QApplication, QMainWindow

import sys


class Window(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle('FactumBreeze')
        self.setGeometry(300, 250, 350, 200)

        self.new_text = QtWidgets.QLabel(self)

        self.test_text = QtWidgets.QLabel(self)
        self.test_text.setText('Weather checker by Heine Inc.')
        self.test_text.move(100, 10)
        self.test_text.adjustSize()

        self.button = QtWidgets.QPushButton(self)
        self.button.move(80, 100)
        self.button.setText('Select JSON log file')
        self.button.setFixedWidth(200)
        self.button.clicked.connect(self.add_label)

    def add_label(self):
        self.new_text.setText('File selected. Analyzing...')
        self.new_text.move(115, 50)
        self.new_text.adjustSize()


app = QApplication(sys.argv)
window = Window()

window.show()

sys.exit(app.exec())
