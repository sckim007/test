pipeline {
    agent any
    stages {
        stage("Checkout") {
            steps {
                git url: 'https://github.com/sckim007/test.git'
            }
        }
        stage("First Stage") {
            steps {
                echo 'Step 1. Hello World'
            }
        }
        stage("Second Stage") {
            steps {
                echo 'Step 2. Hello World'
            }
        }
        stage("Compile") {
            steps {
                sh "gcc hello.c"
            }
        }
    }
}
