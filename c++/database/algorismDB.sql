CREATE TABLE "superadmin" (
  "username" VARCHAR(50) PRIMARY KEY,
  "password" VARCHAR(50) NOT NULL
);

CREATE TABLE "admin" (
  "id" SERIAL PRIMARY KEY,
  "username" VARCHAR(50) NOT NULL,
  "password" VARCHAR(50) NOT NULL
);

CREATE TABLE "student" (
  "id" SERIAL PRIMARY KEY,
  "name" VARCHAR(50),
  "student_id" VARCHAR(20),
  "gender" VARCHAR(10),
  "department" VARCHAR(50),
  "phone" BIGINT,
  "pcname" VARCHAR(50),
  "serial" VARCHAR(50)
);

CREATE TABLE "staff" (
  "id" SERIAL PRIMARY KEY,
  "name" VARCHAR(50),
  "staff_id" VARCHAR(20),
  "gender" VARCHAR(10),
  "job" VARCHAR(50),
  "phone" BIGINT,
  "typeofpc" VARCHAR(20),
  "pcname" VARCHAR(50),
  "serial" VARCHAR(50)
);

CREATE TABLE "nonstaff" (
  "id" SERIAL PRIMARY KEY,
  "name" VARCHAR(50),
  "nonstaff_id" VARCHAR(20),
  "gender" VARCHAR(10),
  "phone" BIGINT,
  "pcname" VARCHAR(50),
  "serial" VARCHAR(50)
);

ALTER TABLE "admin" ADD FOREIGN KEY ("id") REFERENCES "student" ("id");

ALTER TABLE "admin" ADD FOREIGN KEY ("id") REFERENCES "staff" ("id");

ALTER TABLE "admin" ADD FOREIGN KEY ("id") REFERENCES "nonstaff" ("id");
