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
        stage("Unit Test") {
            steps {
                sh "./unit-test"
            }
        }
        stage("Docker Build") {
            steps {
                sh "docker build -t suncheul/hello-alpine ."
            }
        }
        stage("Docker Running") {
            steps {
                sh "docker run -d --rm -p 1010:1010/udp --name hello-alpine hello-alpine"
            }
        }
        stage("Docker Login") {
            steps {
                sh "docker login -u suncheul -p kscksc7315"
            }
        }
        stage("Docker Push") {
            steps {
                sh "docker push suncheul/hello-alpine"
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
