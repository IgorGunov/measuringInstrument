CREATE TABLE OrganizationOfVerification ( /*организация*/
id int IDENTITY(1,1) PRIMARY KEY,
name VARCHAR(255) NOT NULL,
INN VARCHAR(255) NOT NULL,
address VARCHAR(255) NOT NULL
)

CREATE VIEW verificationDate
  AS
  SELECT T1.id AS organizationNumber, T1.name, T3.name AS measuring, DATEADD(MONTH, T3.Verification_interval, T2.verification_date) AS data
  FROM OrganizationOfVerification T1, HistoryOfVerifications T2, MeasuringInstrument T3
  WHERE T1.id = T2.organization_id AND T3.id = T2.tool_id




  SELECT T1.name, (SELECT T2.name 
	FROM measuringInstrument T2 
	WHERE T3.organization_id=T1.id AND T3.tool_id=T2.id) AS measuring
FROM OrganizationOfVerification T1, HistoryOfVerifications T3




CREATE TRIGGER trigger_name
ON ResponsibleEmployee
AFTER INSERT, UPDATE 
AS 
UPDATE ResponsibleEmployee 
SET 
name=UPPER(SUBSTRING(i.name,1,1))+SUBSTRING(i.name,2,len(i.name))
FROM ResponsibleEmployee t
JOIN inserted i ON i.id=t.id





INSERT  INTO OrganizationOfVerification (name, INN, address)
VALUES ('Черничка','123','Москва')
INSERT  INTO OrganizationOfVerification (name, INN, address)
VALUES ('Дядя Ваня','228','Санкт-Петербург')
INSERT  INTO OrganizationOfVerification (name, INN, address)
VALUES ('Атмосфера','010','Сыктывкар')
INSERT  INTO OrganizationOfVerification (name, INN, address)
VALUES ('Уют','458','Саратов')

CREATE TABLE ResponsibleEmployee ( /*ответственные работники*/
id int IDENTITY(1,1) PRIMARY KEY,
name VARCHAR(255) NOT NULL,
first_name VARCHAR(255) NOT NULL,
last_name VARCHAR(255) NOT NULL,
post VARCHAR(255) NOT NULL
)

INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('Иван', 'Иванов', 'Иванович', 'Менеджер')
INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('Петр', 'Грачев', 'Олегович', 'Закупщик')
INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('Денис', 'Петров', 'Игоревич', 'Менеджер')
INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('Кирилл', 'Измайлов', 'Сергеевич', 'Уборщик')

CREATE TABLE MeasuringInstrument ( /*измерительный инструмент*/
id int IDENTITY(1,1) PRIMARY KEY,
name VARCHAR(255) NOT NULL,
accuracy_class VARCHAR(255) NOT NULL,
according_to_standard VARCHAR(255) NOT NULL,
Verification_interval INT NOT NULL,
)

INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('Гаечный ключ', '1', 'ГОСТ', '18')
INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('Микрометр', '2', 'ГОСТ', '6')
INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('Штанген циркуль', '1', 'ГОСТ', '12')
INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('Градусник', '3', 'ГОСТ', '3')

CREATE TABLE EmployeeAndToolRelationship ( /*связь сотрудника и инструмента*/
id int IDENTITY(1,1) PRIMARY KEY,
employe_id INT,
tool_id INT,
FOREIGN KEY (employe_id) REFERENCES ResponsibleEmployee (id),
FOREIGN KEY (tool_id) REFERENCES ResponsibleEmployee (id)
)

CREATE TABLE HistoryOfVerifications ( /*история поверки*/
id int IDENTITY(1,1) PRIMARY KEY,
tool_id INT,
organization_id INT,
FOREIGN KEY (tool_id) REFERENCES MeasuringInstrument (id),
FOREIGN KEY (organization_id) REFERENCES OrganizationOfVerification (id),
verification_date VARCHAR(255) NOT NULL
)
