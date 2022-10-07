CREATE TABLE OrganizationOfVerification ( /*�����������*/
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
VALUES ('��������','123','������')
INSERT  INTO OrganizationOfVerification (name, INN, address)
VALUES ('���� ����','228','�����-���������')
INSERT  INTO OrganizationOfVerification (name, INN, address)
VALUES ('���������','010','���������')
INSERT  INTO OrganizationOfVerification (name, INN, address)
VALUES ('���','458','�������')

CREATE TABLE ResponsibleEmployee ( /*������������� ���������*/
id int IDENTITY(1,1) PRIMARY KEY,
name VARCHAR(255) NOT NULL,
first_name VARCHAR(255) NOT NULL,
last_name VARCHAR(255) NOT NULL,
post VARCHAR(255) NOT NULL
)

INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('����', '������', '��������', '��������')
INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('����', '������', '��������', '��������')
INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('�����', '������', '��������', '��������')
INSERT  INTO ResponsibleEmployee (name, first_name, last_name, post)
VALUES ('������', '��������', '���������', '�������')

CREATE TABLE MeasuringInstrument ( /*������������� ����������*/
id int IDENTITY(1,1) PRIMARY KEY,
name VARCHAR(255) NOT NULL,
accuracy_class VARCHAR(255) NOT NULL,
according_to_standard VARCHAR(255) NOT NULL,
Verification_interval INT NOT NULL,
)

INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('������� ����', '1', '����', '18')
INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('���������', '2', '����', '6')
INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('������� �������', '1', '����', '12')
INSERT  INTO MeasuringInstrument (name, accuracy_class, according_to_standard, Verification_interval)
VALUES ('���������', '3', '����', '3')

CREATE TABLE EmployeeAndToolRelationship ( /*����� ���������� � �����������*/
id int IDENTITY(1,1) PRIMARY KEY,
employe_id INT,
tool_id INT,
FOREIGN KEY (employe_id) REFERENCES ResponsibleEmployee (id),
FOREIGN KEY (tool_id) REFERENCES ResponsibleEmployee (id)
)

CREATE TABLE HistoryOfVerifications ( /*������� �������*/
id int IDENTITY(1,1) PRIMARY KEY,
tool_id INT,
organization_id INT,
FOREIGN KEY (tool_id) REFERENCES MeasuringInstrument (id),
FOREIGN KEY (organization_id) REFERENCES OrganizationOfVerification (id),
verification_date VARCHAR(255) NOT NULL
)
