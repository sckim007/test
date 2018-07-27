pipeline {
    agent any
    triggers {
        pollSCM('* * * * *')
    }
    stages {
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
        stage("Source Build") {
            steps {
                sh "make"
            }
        }
        stage("List") {
            steps {
                sh "ls"
            }
        }
        stage("Docker build") {
            steps {
                sh "docker build -t suncheul/hello-gcc-app ."
            }
        }
        stage("Docker running") {
            steps {
                sh "docker run suncheul/hello-gcc-app"
            }
        }
        stage("Docker login") {
            steps {
                sh "docker login -u suncheul -p kscksc7315"
            }
        }
        stage("Docker push") {
            steps {
                sh "docker push suncheul/hello-gcc-app"
            }
        }
    }
    post {
        always {
            mail to: 'sckim007@etri.re.kr',
            subject: "Completed Pipeline: ${currentBuild.fullDisplayName}",
            body: "Your build completed, please check: ${env.BUILD_URL}"
        }
    }
}
